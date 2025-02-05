#pragma once
#include "CMUgraphicsLib/CMUgraphics.h"


//The folowing struct contains all game configurations
// (MAY be loaded from a configuration file later)
__declspec(selectany) //This line to prevent "redefinition error"
struct 		
{
	int	windWidth=1300, windHeight=600,	//Window width and height
		wx=5, wy=5,			//Window starting coordinates

		//The window is divded into 3 areas: toolbar, Working area, and statusbar
		toolBarHeight=60,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		toolbarItemWidth = 70,			//Width of each icon in toolbar
		statusBarHeight=50;	//Status Bar Height
	
	int remainingHeight = windHeight - toolBarHeight - statusBarHeight;

	int gridHeight = int(remainingHeight * (2 / 3.0)); 		//The grid is where bricks can be drawn

	//Default colors
	color	penColor = BLACK,			//color used to draw borders/write messages
			fillColor = BLACK,			//shapes fill color (Default)
			bkGrndColor= LAVENDER,		//Screen Background color
			statusBarColor = LIGHTSEAGREEN;	//background color of the status
	int penWidth=3;			//width of the pen that draws shapes


	color gridDotsColor = RED;
	int gridSpacing=30;	//spacing between grid points

	////// Configuration for the composite shapes //////
	// default Ref Point for any newly created shape 
	int RefX = windWidth *  (2.0 / 3);
	int RefY = windHeight * (0.5);

	////-----  Sign Shape Confoguration ---------////
	// For the Sign shape, define width and height of both rectangles
	struct {
		int baseWdth = 20, baseHeight = 80;
		int topWdth = 100, topHeight = 50;
	}sighShape;

	struct {
		int recthight = 25, rectwdth = 18;
		int trilen=100;
		int trihigh= trilen *cos(3.14/ 3);
	}Tree;

	struct {
		int rect1_length = 80, rect1_wdth = 20;
		int rect2_length = 65, rect2_wdth = 5;
		int tri1_len = 50;
		int tri1_high = tri1_len * cos(3.14 / 3);
		int tri2_len = 80;
		int tri2_high = tri2_len * cos(3.14 / 3);

	}Boat;

	struct {
		int circ1_rad = 50;
		int circ2_rad = 35;
		int circ3_rad = 12;
		int rec_width = 15, rec_len = 125;

	}Butterfly;
	struct {
		int radius = 26;
		int length = 100;
		int high= length*cos(3.143);
	}cone;
	struct {

		int hght = 100, wdth = 120;//base rectangle
		int t_Len = 120;
		int hght2 = 90, wdth2 = 25;// top rectangle
	}Home;
	struct
	{
		int len1 = 120; //body tri
		int len2 = 20;  //ear tri
		int hght = 80, base = 120;  // face
		int len = 80; //body  //b
		int rad = 10;  //feet

	}Cat;
	struct
	{
		int len = 80, hght = 30; //body
		int rad = 15;
		int len2 = 30; //triangle 
	}car;

}config;


enum toolbarItem //The items of the  toolbar (you should add more items)
{
	//Note: Items are ordered here as they appear in the toolbar
	//If you want to change the toolbar items order, just change the order here
	ITM_SIGN,		//Sign shape item
	Itm_Tree,
	ITM_Boat,
	ITM_Butterfly,
	ITM_Home,
	ITM_Cat,
	ITM_Car,
	Itm_increase,
	Itm_decrease,
	Itm_rotate,
	ITM_flip,
	Itm_refresh,
	Itm_hint,
	Itm_delet,
	Itm_S_G_LEVEL,
	Itm_load,
	Itm_SAVE,
	ITM_EXIT,		//Exit item
	              //TODO: Add more items names here
	ITM_CNT		//no. of toolbar items ==> This should be the last line in this enum

};



