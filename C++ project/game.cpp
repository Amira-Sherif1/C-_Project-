#include "game.h"
#include "gameConfig.h"
#include "toolbar.h"



game::game()
{

	//Create the main window
	createWind(config.windWidth, config.windHeight, config.wx, config.wy);

	//Create and draw the toolbar
	createToolBar();

	//Create and draw the grid
	createGrid();
	shapesGrid->draw();	//draw the grid and all shapes it contains.

	//Create and clear the status bar
	clearStatusBar();
}

game::~game()
{
	delete pWind;
	delete shapesGrid;
}


//////////////////////////////////////////////////////////////////////////////////////////
void game::createWind(int w, int h, int x, int y) 
{
	pWind = new window(w, h, x, y);
	pWind->SetBrush(config.bkGrndColor);
	pWind->SetPen(config.bkGrndColor, 1);
	pWind->DrawRectangle(0, 0, w, h);
}
//////////////////////////////////////////////////////////////////////////////////////////
void game::clearStatusBar() const
{
	//Clear Status bar by drawing a filled rectangle
	pWind->SetPen(config.statusBarColor, 1);
	pWind->SetBrush(config.statusBarColor);
	pWind->DrawRectangle(0, config.windHeight - config.statusBarHeight, config.windWidth, config.windHeight);
}

//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the mode
void game::createToolBar()
{
	gameToolbar = new toolbar(this);
}

void game::createGrid()
{	
	//calc some grid parameters
	point gridUpperLeftPoint = { 0, config.toolBarHeight };
	int gridHeight = config.windHeight - config.toolBarHeight - config.statusBarHeight;
	//create the grid
	shapesGrid = new grid(gridUpperLeftPoint, config.windWidth, gridHeight, this);
}

operation* game::createRequiredOperation(toolbarItem clickedItem)
{
	void ToolbarClicker();	//creates the text of the item
	operation* op=nullptr;
	switch (clickedItem)
	{
	case ITM_SIGN:
		op = new operAddSign(this);
		break;
	case Itm_Tree:
		op = new operAddTree(this);
	}
	return op;
}


//////////////////////////////////////////////////////////////////////////////////////////

void game::printMessage(string msg) const	//Prints a message on status bar
{
	clearStatusBar();	//First clear the status bar

	pWind->SetPen(config.penColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, config.windHeight - (int)(0.85 * config.statusBarHeight), msg);
}



window* game::getWind() const		//returns a pointer to the graphics window
{
	return pWind;
}



string game::getSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			if (Label.size() > 0)
				Label.resize(Label.size() - 1);
			else
				Key = '\0';
		else
			Label += Key;
		printMessage(Label);
	}
}

grid* game::getGrid() const
{
	// TODO: Add your implementation code here.
	return shapesGrid;
}



////////////////////////////////////////////////////////////////////////
void game::run() 
{
	//This function reads the position where the user clicks to determine the desired operation
	int x, y;
	bool isExit = false;

	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - SHAPE HUNT (CIE 101 / CIE202 - project) - - - - - - - - - -");
	toolbarItem clickedItem=ITM_CNT;
	do
	{
		//printMessage("Ready...");
		//1- Get user click
		pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

		//2-Explain the user click
		//If user clicks on the Toolbar, ask toolbar which item is clicked
		if (y >= 0 && y < config.toolBarHeight)
		{
			clickedItem=gameToolbar->getItemClicked(x);

			//3-create the approp operation accordin to item clicked by the user
			operation* op = createRequiredOperation(clickedItem);
			if (op)
				op->Act();

			//4-Redraw the grid after each action
			shapesGrid->draw();
			
			ToolbarClicker(clickedItem);
		}	

	} while (clickedItem!=ITM_EXIT);
}


void game::ToolbarClicker(toolbarItem t) {
	string text;
	switch (t) {
	case(ITM_SIGN):
		text = "You Pressed on Sign item";
		break;
	case(Itm_Tree):
		text = "You Pressed on Tree item";
		break;
	case(ITM_Boat):
		text = "You Pressed on Boat item";
		break;
	case(ITM_Butterfly):
		text = "You Pressed on Butterfly item";
		break;
	case(ITM_moon):
		text = "You Pressed on Moon item";
		break;
	case(ITM_rocket):
		text = "You Pressed on Rocket item";
		break;
	case(ITM_cone):
		text = "You Pressed on Cone item";
		break;
	case(Itm_increase):
		text = "You Pressed on Increase item";
		break;
	case(Itm_decrease):
		text = "You Pressed on Decrease item";
		break;
	case(Itm_rotate):
		text = "You Pressed on Rotate item";
		break;
	case(ITM_flip):
		text = "You Pressed on Flip item";
		break;
	case(Itm_refresh):
		text = "You Pressed on Refresh item";
		break;
	case(Itm_hint):
		text = "You Pressed on Hint item";
		break;
	case(Itm_delet):
		text = "You Pressed on Delete item";
		break;
	case(Itm_S_G_LEVEL):
		text = "You Pressed on Select Game Level item";
		break;
	case(Itm_load):
		text = "You Pressed on Load item";
		break;
	case(Itm_SAVE):
		text = "You Pressed on Save item";
		break;
	}
	pWind->SetPen(BLACK);
	pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->DrawString(10, config.windHeight - 40, text);
	Sleep(500);
	clearStatusBar();
	}