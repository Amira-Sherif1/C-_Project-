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
	delete pGrid->getactiveshap();

	pGrid->setActiveShape(psh);

}
operAddTree::operAddTree(game* p_Game): operation(p_Game)
{
}
void operAddTree::Act() {

	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefY % config.gridSpacing;

	point TreeShapeRef = { xGrid , yGrid };

	shape* ptr = new Tree(pGame, TreeShapeRef);

	grid* pGrid = pGame->getGrid();
	delete pGrid->getactiveshap();
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
	int xw = config.RefX - config.RefX % config.gridSpacing;
	int yw = config.RefY - config.RefY % config.gridSpacing;
	point ButterflyPointRef = { xw , yw };
	shape* btfl = new Butterfly(pGame, ButterflyPointRef);
	grid* gg = pGame->getGrid();
	delete gg->getactiveshap();
	gg->setActiveShape(btfl);
}

//Home
operAddHome::operAddHome(game* r_pGame) :operation(r_pGame)
{
}

void operAddHome::Act()
{
	int xw = config.RefX - config.RefX % config.gridSpacing;
	int yw = config.RefY - config.RefY % config.gridSpacing;
	point HomeRef = { xw,yw };
	shape* ph = new Home(pGame, HomeRef);
	grid* gg = pGame->getGrid();
	delete gg->getactiveshap();
	gg->setActiveShape(ph);
}

//Cat 

operAddCat::operAddCat(game* r_pGame) :operation(r_pGame)
{
}

void operAddCat::Act()
{
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefY % config.gridSpacing;
	point CatRef = { xGrid,yGrid };
	shape* psh = new Cat(pGame, CatRef);
	grid* pGrid = pGame->getGrid();
	delete pGrid->getactiveshap();
	pGrid->setActiveShape(psh);
}

//Car
operAddcar::operAddcar(game* r_pGame) : operation(r_pGame) {
}
void operAddcar::Act() {

	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefY % config.gridSpacing;

	point CarShapeRef = { xGrid , yGrid };

	shape* pcr = new car(pGame, CarShapeRef);

	grid* pGrid = pGame->getGrid();
	delete pGrid->getactiveshap();
	pGrid->setActiveShape(pcr);
}

operResizeUp::operResizeUp(game* r_pGame) :operation(r_pGame) {

}
void operResizeUp::Act() {
	grid* pGrid = pGame->getGrid();
	shape* sh= pGrid->getactiveshap();
	sh->ResizeUp();
	sh->draw();
}
operResizeDown::operResizeDown(game* r_pGame) :operation(r_pGame) {

}

void operResizeDown::Act() {
	grid* pgrid = pGame->getGrid();
	shape* sh = pgrid->getactiveshap();
	sh->ResizeDown();
	sh->draw();
}

operDelete::operDelete(game* r_pGame) :operation(r_pGame)
{

}

void operDelete::Act()
{
	grid* pGrid = pGame->getGrid();
	pGrid->deleteShape();
}
operRefresh::operRefresh(game* r_pGame):operation(r_pGame){}

void operRefresh::Act() {
	
	grid* pGrid = pGame->getGrid();
	if (pGame->getlives() > 0) {
		/*if (pGame->getlevel() < 3) {
			do {
				pGrid->delete_shapelist();
				pGrid->Random_Shapes_Generator();
			} while (pGrid->overlap());
			pGrid->draw();
		}

		else if (pGame->getlevel() >= 3) {
			do {
				pGrid->delete_shapelist();
				pGrid->Random_Shapes_Generator();
			} while (!(pGrid->overlap()));
			pGrid->draw();

		}*/
		pGrid->delete_shapelist();
		pGrid->Random_Shapes_Generator();
		//pGrid->checkoverlaping();
		pGrid->draw();
		pGame->setlives(pGame->getlives() - 1);
	}
	
}
operSelectLevel::operSelectLevel(game* r_pGame) :operation(r_pGame) {}


void operSelectLevel::Act()
{
	window* pw = pGame->getWind();
	grid* pgrid = pGame->getGrid();
	keytype kt = ASCII;
	char k;
	kt = pw->WaitKeyPress(k);
	int l = int(k);
	while (l > 48 && l < 57)
	{
		int level = l - 48;
		pGame->setlevel(level);

		//pGame->UpdateInfo();
	}

}


operSave::operSave(game* r_pGame) :operation(r_pGame) {}

void operSave::Act()
{
	grid* pgrid = pGame->getGrid();
	pgrid->Save();
}

operLoad::operLoad(game* r_pGame) :operation(r_pGame) {}


void operLoad::Act()
{
	grid* pgrid = pGame->getGrid();
	pgrid->Load();
}

operrotate::operrotate(game* r_pGame) :operation(r_pGame) {}
void operrotate::Act() {

	grid* pGrid = pGame->getGrid();
	shape* sh = pGrid->getactiveshap();
	/*sh->rotate();*/
}
operVerticalflip::operVerticalflip(game* r_pGame) :operation(r_pGame) {}
void operVerticalflip::Act() {

	grid* pGrid = pGame->getGrid();
	shape* sh = pGrid->getactiveshap();
	//sh->VerticalFlip();
}
operHint::operHint(game* r_pGame) :operation(r_pGame) {}
void operHint::Act() {

	if (pGame->getlevel() >= 3) {
		grid* pGrid = pGame->getGrid();
		shape* sh = pGrid->GetHintShape();
		sh->Setcolor();
		Sleep(2000);
		pGame->setScore(pGame->GetScore() - 1);

	}


}

operExit::operExit(game* r_pGame) :operation(r_pGame) {}
void operExit::Act() {
	grid *w = pGame->getGrid();
	w->Save();
	pGame->SetExit();
}

