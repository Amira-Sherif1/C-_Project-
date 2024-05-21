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
	delete gameToolbar;
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
		break;
	/*case ITM_Boat:
		op = new operAddBoat(this);
		break;*/
	case ITM_Butterfly:
		op = new operAddButterfly(this);
		break;
	case ITM_Home:
		op = new operAddHome(this);
		break;
	case ITM_Cat:
		op = new operAddCat(this);
		break;
	case ITM_Car:
		op = new operAddcar(this);
		break;
	case Itm_increase:
		op = new operResizeUp(this);
		break;
	case Itm_decrease:
		op = new operResizeDown(this);
		break;
	case Itm_refresh:
		op = new operRefresh(this);
		break;
	case Itm_delet:
		op = new operDelete(this);
		break;
	case Itm_rotate:
		op = new operrotate(this);
		break;
	case ITM_flip:
		op = new operVerticalflip(this);
		break;
	case Itm_hint:
		op = new operHint(this);
		break;
	case ITM_EXIT:
		op = new operExit(this);
		break;
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
	if(shapesGrid!= nullptr)
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
	toolbarItem clickedItem = ITM_CNT;

	
	 if (level  <3) {
		do {
			shapesGrid->delete_shapelist();
			shapesGrid->Random_Shapes_Generator();
		} while (shapesGrid->overlap());
		shapesGrid->draw();
	}

	else if (level >= 3) {
		do {
			shapesGrid->delete_shapelist();
			shapesGrid->Random_Shapes_Generator();
		} while (!(shapesGrid->overlap()));
		shapesGrid->draw();

	}
	//shapesGrid->Random_Shapes_Generator();
	//shapesGrid->checkoverlaping();
	//shapesGrid->draw();


	do
	{
		//printMessage("Ready...");
		//1- Get user click
		pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

		//2-Explain the user click
		//If user clicks on the Toolbar, ask toolbar which item is clicked
		if (y >= 0 && y < config.toolBarHeight)
		{
			clickedItem = gameToolbar->getItemClicked(x);

			//3-create the approp operation accordin to item clicked by the user
			operation* op = createRequiredOperation(clickedItem);
			if (op)
				op->Act();

			//4-Redraw the grid after each action

			shapesGrid->draw();
			

			ToolbarClicker(clickedItem);
		}

		keytype ktype;
		char Key;
		bool stillmoving = true;
		shape* Mirror= shapesGrid->getactiveshap();
		while (stillmoving)
		{
			shapesGrid->draw();
			pWind->FlushKeyQueue();
			ktype = pWind->WaitKeyPress(Key);
		
				if (ktype == ARROW) {    // Call the function to handle the arrow key based on the active shape

					shape* activeShape = shapesGrid->getactiveshap();

					if (activeShape) {
						switch (Key) {
						case 8:
							activeShape->move(8);
							stillmoving = true;
							break;
						case 2:
							activeShape->move(2);
							stillmoving = true;
							break;
						case 6:
							activeShape->move(6);
							stillmoving = true;
							break;
						case 4:
							activeShape->move(4);
							stillmoving = true;
							break;
						}
					}
				}
				if (ktype == ASCII) {
					if (Key == ' ') {
						shapesGrid->Check_Matching();
					}
				}
				else if(ktype == ESCAPE)
					stillmoving =false;

				shapesGrid->setActiveShape(Mirror);
		}
	} while (clickedItem != ITM_EXIT);


};


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
	case(ITM_Home):
		text = "You Pressed on Home item";
		break;
	case(ITM_Cat):
		text = "You Pressed on Cat item";
		break;
	case(ITM_Car):
		text = "You Pressed on Car item";
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
	clearStatusBar();
	pWind->SetPen(BLACK);
	pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->DrawString(10, config.windHeight - 40, text);
	}
int game::getlevel()const {
	return level;
}


int game:: getlives()const {

	return lives;
}

void game::setlives(int x) {
	lives = x;
}

void game::setlevel(int x) {
	level = x;
}
void game::setscore(int x)
{
	x = score;
}

int game::getscore()const
{
	return score;
}
void game::setScore(int s) {
	score = s;

}
int game::GetScore() {

	return score;
}
void game::SetExit() {
	isExit = true;
}
