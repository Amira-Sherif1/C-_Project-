#include "operations.h"
#include "game.h"
#include "CompositeShapes.h"
/////////////////////////////////// class operation  //////////////////
operation::operation(game* r_pGame)
{
	pGame = r_pGame;
}


/////////////////////////////////// class operAddSign  //////////////////

operAddSign::operAddSign(game* r_pGame):operation(r_pGame)
{
}

void operAddSign::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefY % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point signShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new Sign(pGame, signShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}
operAddTree::operAddTree(game* p_Game): operation(p_Game)
{
}
void operAddTree::Act() {
	window* pw= pGame->getWind();

	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefY % config.gridSpacing;

	point TreeShapeRef = { xGrid , yGrid };

	shape* ptr = new Tree(pGame, TreeShapeRef);

	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(ptr);

}
//
////Boat
//operAddBoat::operAddBoat(game* r_pGame) : operation(r_pGame){
//}
//void operAddBoat::Act() {
//	window* pw = pGame->getWind();
//
//	int xGrid = config.RefX - config.RefX % config.gridSpacing;
//	int yGrid = config.RefY - config.RefY % config.gridSpacing;
//
//	point BoatShapeRef = { xGrid , yGrid };
//
//	shape* pbt = new Boat(pGame, BoatShapeRef);
//
//	grid* pGrid = pGame->getGrid();
//	pGrid->setActiveShape(pbt);
//}

operAddButterfly::operAddButterfly(game* p_Game) : operation(p_Game)
{
}
void operAddButterfly::Act() {
	window* win = pGame->getWind();

	int xw = config.RefX - config.RefX % config.gridSpacing;
	int yw = config.RefY - config.RefY % config.gridSpacing;

	point ButterflyPointRef = { xw , yw };

	shape* btfl = new Butterfly(pGame, ButterflyPointRef);

	grid* gg = pGame->getGrid();
	gg->setActiveShape(btfl);

}



//Home
operAddHome::operAddHome(game* r_pGame) :operation(r_pGame)
{
}

void operAddHome::Act()
{
	window* pw = pGame->getWind();


	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefY % config.gridSpacing;



	point HomeRef = { xGrid,yGrid };

	
	shape* ph = new Home(pGame, HomeRef);

	
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(ph);

}

//Cat 

operAddCat::operAddCat(game* r_pGame) :operation(r_pGame)
{
}

void operAddCat::Act()
{

	window* pw = pGame->getWind();


	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefY % config.gridSpacing;

	point CatRef = { xGrid,yGrid };

	shape* psh = new Cat(pGame, CatRef);

	grid* pGrid = pGame->getGrid();

	pGrid->setActiveShape(psh);

}

//Car
operAddcar::operAddcar(game* r_pGame) : operation(r_pGame) {
}
void operAddcar::Act() {
	window* pw =  pGame->getWind();

	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefY % config.gridSpacing;

	point CarShapeRef = { xGrid , yGrid };

	shape* pcr = new car(pGame, CarShapeRef);

	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(pcr);
}

operResizeUp::operResizeUp(game* r_pGame) :operation(r_pGame) {

}
void operResizeUp::Act() {
	window* pw = pGame->getWind();
	grid* pGrid = pGame->getGrid();
	shape* sh= pGrid->getactiveshap();
	sh->ResizeUp();
}
operResizeDown::operResizeDown(game* r_pGame) :operation(r_pGame) {

}

void operResizeDown::Act() {
	window* pw = pGame->getWind();
	grid* pgrid = pGame->getGrid();
	shape* sh = pgrid->getactiveshap();
	sh->ResizeDown();
}

operDelete::operDelete(game* r_pGame) :operation(r_pGame)
{

}

void operDelete::Act()
{
	window* pw = pGame->getWind();
	grid* pGrid = pGame->getGrid();
	pGrid->deleteShape();
}
operRefresh::operRefresh(game* r_pGame):operation(r_pGame){}

void operRefresh::Act() {
	
	grid* pGrid = pGame->getGrid();
	if (pGame->getlives() > 0) {
		pGrid->Random_Shapes_Generator();
		pGrid->draw();
		pGame->setlives(pGame->getlives() - 1);
	}
	
}