#include "toolbar.h"
#include "game.h"
//#include "grid.h"


////////////////////////////////////////////////////  class toolbar   //////////////////////////////////////////////
toolbar::toolbar(game* pG)
{	
	height = config.toolBarHeight;
	width = config.windWidth;
	this->pGame = pG;
	window* pWind = pGame->getWind();
	
	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each toolbar item
	toolbarItemImages[ITM_SIGN] = "images\\toolbarItems\\toolbar_sign.jpg";
	toolbarItemImages[Itm_Tree] = "images\\toolbarItems\\Tree.jpg";
	toolbarItemImages[ITM_Boat] = "images\\toolbarItems\\Boat.jpg";
	toolbarItemImages[ITM_Butterfly] = "images\\toolbarItems\\butterfly.jpg";
	toolbarItemImages[ITM_Home] = "images\\toolbarItems\\Home.jpg";
	toolbarItemImages[ITM_Cat] = "images\\toolbarItems\\Cat.jpg";
	toolbarItemImages[ITM_Car] = "images\\toolbarItems\\car.jpg";
	toolbarItemImages[Itm_increase] = "images\\toolbarItems\\increase.jpg";
	toolbarItemImages[Itm_decrease] = "images\\toolbarItems\\Decrease.jpg";
	toolbarItemImages[Itm_rotate] = "images\\toolbarItems\\rotation.jpg";
	toolbarItemImages[ITM_flip] = "images\\toolbarItems\\flip1.jpg";
	toolbarItemImages[Itm_refresh] = "images\\toolbarItems\\captcha.jpg";
	toolbarItemImages[Itm_hint] = "images\\toolbarItems\\hint.jpg";
	toolbarItemImages[Itm_delet] = "images\\toolbarItems\\DeleteIcon.jpg";	
	toolbarItemImages[Itm_S_G_LEVEL] = "images\\toolbarItems\\level-up.jpg";
	toolbarItemImages[Itm_load] = "images\\toolbarItems\\Load.jpg";
	toolbarItemImages[Itm_SAVE] = "images\\toolbarItems\\download.jpg";
	toolbarItemImages[ITM_EXIT] = "images\\toolbarItems\\exit.jpg";
	                                                   //TODO: Prepare image for each toolbar item and add it to the list

	//Draw toolbar item one image at a time
	for (int i = 0; i < ITM_CNT; i++)
		pWind->DrawImage(toolbarItemImages[i], i * config.toolbarItemWidth, 0, config.toolbarItemWidth, height);


	//Draw a line under the toolbar
	pWind->SetPen(DARKBLUE, 3);
	pWind->DrawLine(0, height,width , height);
}



//handles clicks on toolbar icons, returns ITM_CNT if the click is not inside the toolbar
toolbarItem toolbar::getItemClicked(int x)
{
	
	if (x > ITM_CNT * config.toolbarItemWidth)	//click outside toolbar boundaries
		return ITM_CNT;
	
	
	//Check whick toolbar item was clicked
	//==> This assumes that toolbar items are lined up horizontally <==
	//Divide x coord of the point clicked by the icon width (int division)
	//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

	return (toolbarItem)(x / config.toolbarItemWidth);

}

void toolbar::drawInitialInfo()
{
	window* pWind = pGame->getWind();
	pWind->SetPen(DARKBLUE);
	pWind->DrawString(10, 5, "Lives: 5");
	pWind->DrawString(150, 5, "Score: 0");
	pWind->DrawString(300, 5, "Level: 1");
}

void toolbar::updateInfo(int lives, int score, int level)
{
	window* pWind = pGame->getWind();
	pWind->SetPen(config.bkGrndColor);
	pWind->SetBrush(config.bkGrndColor);
	pWind->DrawRectangle(10, 5, 145, height, FILLED);
	pWind->DrawRectangle(150, 5, 295, height, FILLED);
	pWind->DrawRectangle(300, 5, 445, height, FILLED);

	pWind->SetPen(DARKBLUE);
	pWind->DrawString(10, 5, "Lives: " + to_string(lives));
	pWind->DrawString(150, 5, "Score: " + to_string(score));
	pWind->DrawString(300, 5, "Level: " + to_string(level));
}