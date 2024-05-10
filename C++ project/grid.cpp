#include "grid.h"
#include "game.h"
#include "gameConfig.h"


grid::grid(point r_uprleft, int wdth, int hght, game* pG)
{
	uprLeft = r_uprleft;
	height = hght;
	width = wdth;
	pGame = pG;
	rows = height / config.gridSpacing;
	cols = width / config.gridSpacing;
	shapeCount = 0;

	for (int i = 0; i < MaxShapeCount; i++)
		shapeList[i] = nullptr;

	activeShape = nullptr;

}

grid::~grid()
{
	for (int i = 0; i < shapeCount; i++)
		delete shapeList[i];
}

void grid::draw() const
{
	clearGridArea();
	window* pWind = pGame->getWind();
	
	pWind->SetPen(config.gridDotsColor,1);
	pWind->SetBrush(config.gridDotsColor);
	//draw dots showing the grid reference points
	for (int r = 1; r < rows; r++)
		for (int c = 0; c < cols; c++)
			pWind->DrawCircle(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y, 1);
			//pWind->DrawPixel(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y);

	//Draw ALL shapes
	for (int i = 0; i < shapeCount; i++) {
		if (pGame->getlevel() < 3) {
			pWind->SetPen(getcolor(i), config.penWidth);
			pWind->SetBrush(getcolor(i));
			if (shapeList[i])
				shapeList[i]->draw();
		}

		else {
			pWind->SetPen(config.fillColor, config.penWidth);
			pWind->SetBrush(config.fillColor);
			if (shapeList[i])
				shapeList[i]->draw();	//draw each shape
		}
		pWind->SetPen(config.fillColor, config.penWidth);
		pWind->SetBrush(config.fillColor);
		
	}
			

	//Draw the active shape
	if(activeShape)
		activeShape->draw();
}

void grid::clearGridArea() const
{
	window* pWind = pGame->getWind();	
	pWind->SetPen(config.bkGrndColor, 1);
	pWind->SetBrush(config.bkGrndColor);
	pWind->DrawRectangle(uprLeft.x, uprLeft.y, uprLeft.x + width, uprLeft.y + height);
}

//Adds a shape to the randomly created shapes list.
bool grid::addShape(shape* newShape)
{
	//TODO:
	// 1- Check that the shape can be drawn witout being clipped by grid boundaries
	// 2- check shape count doesn't exceed maximum count
	// return false if any of the checks fail
	
	//Here we assume that the above checks are passed
	shapeList[shapeCount++] = newShape;
	return true;
}

void grid::setActiveShape(shape* actShape)
{
	activeShape = actShape;
}

void grid::deleteShape()
{
	clearGridArea();
	setActiveShape(nullptr);
	draw();
}

shape* grid::getactiveshap()const {
	return activeShape;
}


void grid::randomshape(shape* randshape , int size) {
	for (int i = 0; i < size; i++) {
		switch (resize(size)) {
		case up:
			randshape->ResizeUp();
			break;
		case down:
			randshape->ResizeDown();
			break;
		}
	}
}

void grid::Random_Shapes_Generator() {

	window* pwind = pGame->getWind();

	toolbarItem clickedItem = ITM_CNT;

	srand(time(0));

	for (int j = 0; j < 2 * pGame-> getlevel() - 1; j++) {

		int size = rand() % (1 + 1);    // random resize up or down 
		int x = 100 + rand() % (810 - 100 + 1);   // random the ref point 
		int y = 180 + rand() % (305 - 120 + 1);
		int xref= x - x % config.gridSpacing;
		int yref = y - y % config.gridSpacing;
		point ref = { xref,yref };
		int sh = rand() % (5 + 1);   // choose a random shape from the enum


		
			
		switch (shapes(sh)) {
			case sign: 

				shapeList[j] = new Sign(pGame, ref);
				shapeCount++;
				randomshape(shapeList[j], size);

			
				break;

			case tree:

				shapeList[j] = new Tree(pGame, ref);
				shapeCount++;
				randomshape(shapeList[j], size);

				break;
			/*case boat:
					shapeList[j] = new Boot(pGame, ref);
					shapeCount++;
					randomshape(shapeList[j], size);

				break;*/
			case butter:

				shapeList[j] = new Butterfly(pGame, ref);
				shapeCount++;
				randomshape(shapeList[j], size);
				break;

			case home:

				shapeList[j] = new Home(pGame, ref);
				shapeCount++;
				randomshape(shapeList[j], size);
				break;

			case cat:

				shapeList[j] = new Cat(pGame, ref);
				shapeCount++;
				randomshape(shapeList[j], size);
				break;

			case Car:

				shapeList[j] = new car(pGame, ref);
				shapeCount++;
				randomshape(shapeList[j], size);

				break;

			}
		}
			

	
}
color grid::getcolor(int x)const {
	
	color arry[]= { RED, DARKGREEN, MEDIUMPURPLE, CORNFLOWERBLUE, ORANGE};
	return arry[x];
}