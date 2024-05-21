#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"
#include "toolbar.h"
#include "operations.h"
#include "grid.h"
#include<cstdlib>
#include<time.h>



//Main class that coordinates the game operation
class game
{

	/// Add more members if needed

	toolbar* gameToolbar;
	
	window* pWind;	//Pointer to the CMU graphics window
	grid* shapesGrid;
	int level = 2;
	int lives = 5;
	int score = 5;
	bool isExit = false;

public:
	game();
	~game();

	string getSrting() const;	 //Returns a string entered by the user
	void createWind(int, int, int, int); //creates the game window
	void clearStatusBar() const;	//Clears the status bar
	void printMessage(string msg) const;	//Print a message on Status bar
	void createToolBar();		//creates the toolbar
	void createGrid();		//creates the shapes grid
	window* getWind() const;		//returns a pointer to the graphics window
	grid* getGrid() const;		//returns a pointer to the shapes grid

	//creates an operation according to the toolbar item clicked
	operation* createRequiredOperation(toolbarItem clickedItem);

	//show which item clicked on the toolbar and print it on the screen
	void ToolbarClicker(toolbarItem clickedItem);
	int  getlevel ()const;
	void run();	//start the game
	int getlives() const;
	void setlives(int x);
	void setscore(int x);
	void addscore(int x);
	int getscore()const;
	void setlevel(int x);
	int GetScore();
	void SetExit();

	void semirun(int &ra);

};

