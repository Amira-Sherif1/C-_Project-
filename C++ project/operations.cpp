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
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

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
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	point TreeShapeRef = { xGrid , yGrid };

	shape* ptr = new Tree(pGame, TreeShapeRef);

	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(ptr);

}

operAddButterfly::operAddButterfly(game* p_Game) : operation(p_Game)
{
}
void operAddButterfly::Act() {
	window* win = pGame->getWind();

	int xw = config.RefX - config.RefX % config.gridSpacing;
	int yw = config.RefY - config.RefX % config.gridSpacing;

	point ButterflyPointRef = { xw , yw };

	shape* btfl = new Butterfly(pGame, ButterflyPointRef);

	grid* gg = pGame->getGrid();
	gg->setActiveShape(btfl);

}

/*operAddCone::operAddCone(game* r_pGame) :operation(r_pGame)
{
}

void operAddCone::Act()
{
	window* pw = pGame->getWind();


	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;



	point coneRef = { xGrid,yGrid };

	//create a cone 
	shape* psh = new Cone(pGame, coneRef);

	//Add the cone to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}*/


//Home
operAddHome::operAddHome(game* r_pGame) :operation(r_pGame)
{
}

void operAddHome::Act()
{
	window* pw = pGame->getWind();


	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;



	point HomeRef = { xGrid,yGrid };

	//create a cone 
	shape* psh = new Home(pGame, HomeRef);

	//Add the cone to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}

//Cat 

operAddCat::operAddCat(game* r_pGame) :operation(r_pGame)
{
}

void operAddCat::Act()
{

	window* pw = pGame->getWind();


	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	point CatRef = { xGrid,yGrid };

	shape* psh = new Cat(pGame, CatRef);

	grid* pGrid = pGame->getGrid();

	pGrid->setActiveShape(psh);

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
