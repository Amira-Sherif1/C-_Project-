#include "CompositeShapes.h"
#include "gameConfig.h"
#include "grid.h"
#include "game.h"

////////////////////////////////////////////////////  class Sign  ///////////////////////////////////////
Sign::Sign(game* r_pGame, point ref):shape(r_pGame, ref)
{
	//calc the ref point of the Sign base and top rectangles relative to the Sign shape
	point topRef = ref;	//top rect ref is the same as the sign
	point baseRef = { ref.x, ref.y + config.sighShape.topHeight / 2 + config.sighShape.baseHeight / 2 };
	top = new Rect(pGame, topRef, config.sighShape.topHeight, config.sighShape.topWdth);
	base = new Rect(pGame, baseRef, config.sighShape.baseHeight, config.sighShape.baseWdth);
}
Sign::~Sign() {
	delete base;
	delete top;
}

void Sign::draw() const
{
	base->draw();
	top->draw();
}

void Sign::ResizeUp() {

	stepsCounter += 1;

	if (size >= 2)
		return;

	top->ResizeUp();
	base->ResizeUp();
	size *= 2;
	base->setRefPoint({ RefPoint.x, RefPoint.y + int(config.sighShape.topHeight *size / 2 + config.sighShape.baseHeight*size / 2) });
	//draw();
}


void Sign::ResizeDown(){

	stepsCounter += 1;

	base->ResizeDown();
	top->ResizeDown();

	size /= 2;
	base->setRefPoint({ RefPoint.x, RefPoint.y + int(config.sighShape.topHeight * size / 2 + config.sighShape.baseHeight * size / 2) });
	//draw();

}


void Sign::move(char step) {
	grid* pGrid = pGame->getGrid();

	int y1 = config.toolBarHeight + config.wy + top->gethght();
	int y2 = config.wy + config.windHeight - config.statusBarHeight - base->gethght() - config.statusBarHeight - .5 *top->gethght();
	int x1 = config.wx + top->getwdth();
	int x2 = config.wx + config.windWidth - top->getwdth();
	
	stepsCounter += 1;

	if (step == 8&& (RefPoint.y > y1))
	{
		RefPoint.y = RefPoint.y - config.gridSpacing;
		pGrid->deleteShape();
		base->move(step);
		top->move(step);
		draw();

	}
	else if (step==2 && RefPoint.y < y2)
	{
		RefPoint.y = RefPoint.y + config.gridSpacing;
		pGrid->deleteShape();
		base->move(step);
		top->move(step);
		draw();
	}
	else if (step==6 && RefPoint.x < x2 )
	{
		RefPoint.x = RefPoint.x + config.gridSpacing;
		pGrid->deleteShape();
		base->move(step);
		top->move(step);
		draw();
	}
	else if (step==4 && RefPoint.x > x1)
	{
		RefPoint.x = RefPoint.x - config.gridSpacing;
		pGrid->deleteShape();
		base->move(step);
		top->move(step);
		draw();
	}


}
void Sign::VerticalFlip() {
	
	stepsCounter += 1;
	
	base->setRefPoint( { RefPoint.x, RefPoint.y -( config.sighShape.topHeight / 2 + config.sighShape.baseHeight / 2 )});
	base->VerticalFlip();
}

string Sign::MyType() {
	return "Sign";
}

void Sign::rotate(int angle)
{
}

                 /////////////////////////calss Tree////////////////////

Tree::Tree(game* r_pGame, point ref) :shape(r_pGame, ref) {
	//ref for the tree at the top of the rectangle in the middle
	point T1_ref = { ref.x - config.Tree.trilen / 2,ref.y };
	point T2_ref = { ref.x - config.Tree.trilen / 2,ref.y - config.Tree.trihigh *1/3};
	point T3_ref = { ref.x - config.Tree.trilen / 2,ref.y - config.Tree.trihigh * 2/3 };
	point T4_ref = { ref.x - config.Tree.trilen / 2,ref.y - config.Tree.trihigh * 1};
	point rect_ref = { ref.x,ref.y + config.Tree.recthight / 2 };
	root=new Rect(r_pGame,rect_ref, config.Tree.recthight, config.Tree.rectwdth);
	T1 = new Triangle(r_pGame, config.Tree.trilen, T1_ref);
	T2 = new Triangle(r_pGame, config.Tree.trilen, T2_ref);
	T3 = new Triangle(r_pGame, config.Tree.trilen, T3_ref);
	T4 = new Triangle(r_pGame, config.Tree.trilen, T4_ref);
}
Tree::~Tree() {
	delete T1, T2, T3, T4, root;
}
void Tree::draw() const
{
	T1->draw();
	T2->draw();
	T3->draw();
	T4->draw();
	root->draw();
}
void Tree::ResizeUp(){
	
	stepsCounter += 1;

	if (size >= 2)
		return;

	root->ResizeUp();
	T1->ResizeUp();
	T2->ResizeUp();
	T3->ResizeUp();
	T4->ResizeUp();
	size *= 2;
	T1->setRefPoint({ RefPoint.x - int(config.Tree.trilen * size / 2),RefPoint.y });
	T2->setRefPoint({ RefPoint.x - int(config.Tree.trilen * size / 2),RefPoint.y - int(config.Tree.trihigh * size * 1 / 3 )});
	T3->setRefPoint({ RefPoint.x - int(config.Tree.trilen * size / 2),RefPoint.y - int(config.Tree.trihigh * size * 2 / 3 )});
	T4->setRefPoint({ RefPoint.x - int(config.Tree.trilen * size / 2),RefPoint.y - int(config.Tree.trihigh * size * 1 )});
	root->setRefPoint({ RefPoint.x,RefPoint.y + int(config.Tree.recthight * size / 2) });
	
	//draw();
}
void Tree::ResizeDown() {

	stepsCounter += 1;

	root->ResizeDown();
	T1->ResizeDown();
	T2->ResizeDown();
	T3->ResizeDown();
	T4->ResizeDown();

	size /= 2;
	T1->setRefPoint({ RefPoint.x - int(config.Tree.trilen * size / 2),RefPoint.y });
	T2->setRefPoint({ RefPoint.x - int(config.Tree.trilen * size / 2),RefPoint.y - int(config.Tree.trihigh * size * 1 / 3) });
	T3->setRefPoint({ RefPoint.x - int(config.Tree.trilen * size / 2),RefPoint.y - int(config.Tree.trihigh * size * 2 / 3) });
	T4->setRefPoint({ RefPoint.x - int(config.Tree.trilen * size / 2),RefPoint.y - int(config.Tree.trihigh * size * 1) });
	root->setRefPoint({ RefPoint.x,RefPoint.y + int(config.Tree.recthight * size / 2) });

	//draw();
}

void Tree::move(char step) {
	grid* pGrid = pGame->getGrid();
	int x1 = config.wx +.75*T1->getlength();
	int x2 = config.wx + config.wx + config.windWidth - T1->getlength();
	int y1 = config.wy + config.toolBarHeight + 2.5*T1->gethight();
	int y2 = config.wy + config.windHeight - config.statusBarHeight - 2* root->gethght();
		
	stepsCounter += 1;

		if (step == 8 && RefPoint.y > y1)  //up
		{
			RefPoint.y = RefPoint.y - config.gridSpacing;
			pGrid->deleteShape();
			T1->move(step);
			T2->move(step);
			T3->move(step);
			T4->move(step);
			root->move(step);

			draw();
		}
		else if (step == 2&&RefPoint.y < y2)   //down
		{
			RefPoint.y = RefPoint.y + config.gridSpacing;
			pGrid->deleteShape();
			T1->move(step);
			T2->move(step);
			T3->move(step);
			T4->move(step);
			root->move(step);

			draw();
		}
		else if (step == 6 && RefPoint.x < x2)  // right
		{
			RefPoint.x = RefPoint.x + config.gridSpacing;
			pGrid->deleteShape();
			T1->move(step);
			T2->move(step);
			T3->move(step);
			T4->move(step);
			root->move(step);

			draw();
		}
		else if (step == 4 && RefPoint.x > x1)      //left
		{
			RefPoint.x = RefPoint.x - config.gridSpacing;
			pGrid->deleteShape();
			T1->move(step);
			T2->move(step);
			T3->move(step);
			T4->move(step);
			root->move(step);

			draw();
		}
}

void Tree::VerticalFlip() {

	stepsCounter += 1;

	T1->setRefPoint({ RefPoint.x - config.Tree.trilen / 2,RefPoint.y });
	T2->setRefPoint({ RefPoint.x - config.Tree.trilen / 2, RefPoint.y + config.Tree.trihigh * 1 / 3 });
	T3->setRefPoint({ RefPoint.x - config.Tree.trilen / 2,RefPoint.y + config.Tree.trihigh * 2 / 3 });
	T4->setRefPoint({ RefPoint.x - config.Tree.trilen / 2,RefPoint.y + config.Tree.trihigh * 1 });
	root->setRefPoint({ RefPoint.x,RefPoint.y - config.Tree.recthight / 2 });
	T1->VerticalFlip();
	T2->VerticalFlip();
	T3->VerticalFlip();
	T4->VerticalFlip();
	root->VerticalFlip();
}
void Tree::rotate(int angle)
{
	switch (angle)
	{
	case 90:
		T1->rotate(90);
		T2->rotate(90);
		T3->rotate(90);
		T4->rotate(90);
		root->rotate(90);
		T1->setRefPoint({ RefPoint.x,RefPoint.y - config.Tree.trilen / 2, });
		T2->setRefPoint({ RefPoint.x + config.Tree.trihigh * 1 / 3 ,RefPoint.y - config.Tree.trilen / 2 });
		T3->setRefPoint({ RefPoint.x + config.Tree.trihigh * 2 / 3 ,RefPoint.y - config.Tree.trilen / 2 });
		T4->setRefPoint({ RefPoint.x + config.Tree.trihigh * 1  ,RefPoint.y - config.Tree.trilen / 2 });
		root->setRefPoint({ RefPoint.x + config.Tree.recthight / 2,RefPoint.y });
		break;
	case 180:
		T1->rotate(180);
		T2->rotate(180);
		T3->rotate(180);
		T4->rotate(180);
		root->rotate(180);
		T1->setRefPoint({ RefPoint.x + config.Tree.trilen / 2,RefPoint.y });
		T2->setRefPoint({ RefPoint.x + config.Tree.trilen / 2,RefPoint.y + config.Tree.trihigh * 1 / 3 });
		T3->setRefPoint({ RefPoint.x + config.Tree.trilen / 2,RefPoint.y + config.Tree.trihigh * 2 / 3 });
		T4->setRefPoint({ RefPoint.x + config.Tree.trilen / 2,RefPoint.y + config.Tree.trihigh * 1 });
		root->setRefPoint({ RefPoint.x,RefPoint.y - config.Tree.recthight / 2 });
		break;
	case 270:
		T1->rotate(270);
		T2->rotate(270);
		T3->rotate(270);
		T4->rotate(270);
		root->rotate(90);
		T1->setRefPoint({ RefPoint.x,RefPoint.y + config.Tree.trilen / 2, });
		T2->setRefPoint({ RefPoint.x - config.Tree.trihigh * 1 / 3 ,RefPoint.y + config.Tree.trilen / 2 });
		T3->setRefPoint({ RefPoint.x - config.Tree.trihigh * 2 / 3 ,RefPoint.y + config.Tree.trilen / 2 });
		T4->setRefPoint({ RefPoint.x - config.Tree.trihigh * 1  ,RefPoint.y + config.Tree.trilen / 2 });
		root->setRefPoint({ RefPoint.x + config.Tree.recthight / 2,RefPoint.y });
		break;

	default:
		break;
	}
}
string Tree::MyType() {
	return "Tree";
}
                 //////////////////////class Butterfly////////////////////////

Butterfly::Butterfly(game* r_pgame, point ref) : shape(r_pgame, ref){
	point cir1_ref{ ref.x + config.Butterfly.circ1_rad - config.Butterfly.rec_width, ref.y - config.Butterfly.rec_len /4};
	point cir4_ref{ ref.x - config.Butterfly.circ1_rad + config.Butterfly.rec_width, ref.y - config.Butterfly.rec_len / 4 };
	point cir2_ref{ ref.x + config.Butterfly.circ1_rad - config.Butterfly.rec_width, ref.y + config.Butterfly.rec_len / 4 };
	point cir5_ref{ ref.x - config.Butterfly.circ1_rad + config.Butterfly.rec_width, ref.y + config.Butterfly.rec_len / 4 };
	point cir3_ref{ ref.x , ref.y - config.Butterfly.rec_len / 2 };
	point rect_ref{ ref.x,ref.y };
	cir1 = new circle( r_pgame,cir1_ref,config.Butterfly.circ1_rad );
	cir2 = new circle(r_pgame, cir2_ref, config.Butterfly.circ2_rad);
	cir3= new circle(r_pgame, cir3_ref, config.Butterfly.circ3_rad);
	cir4 = new circle(r_pgame, cir4_ref, config.Butterfly.circ1_rad);
	cir5 = new circle(r_pgame, cir5_ref, config.Butterfly.circ2_rad);
	rect = new Rect(r_pgame, rect_ref, config.Butterfly.rec_len,config.Butterfly.rec_width);
}
Butterfly::~Butterfly() {
	delete cir1, cir2, cir3, cir4, cir5, rect;
}
void Butterfly::draw() const{
	cir2->draw();
	cir5->draw();
	cir1->draw();
	cir4->draw();
	cir3->draw();
	rect->draw();
}
void Butterfly::ResizeUp(){

	stepsCounter += 1;
	
	if (size >= 2)
		return ;
	cir1->ResizeUp();
	cir2->ResizeUp();
	cir3->ResizeUp();
	cir4->ResizeUp();
	cir5->ResizeUp();
	rect->ResizeUp();

	size *= 2;
	cir1->setRefPoint({ RefPoint.x + int((config.Butterfly.circ1_rad - config.Butterfly.rec_width) *size), RefPoint.y - int(config.Butterfly.rec_len * size / 4) });
	cir4->setRefPoint({ RefPoint.x - int((config.Butterfly.circ1_rad - config.Butterfly.rec_width) * size), RefPoint.y - int(config.Butterfly.rec_len * size / 4) });
	cir2->setRefPoint({ RefPoint.x + int((config.Butterfly.circ1_rad - config.Butterfly.rec_width) * size), RefPoint.y + int(config.Butterfly.rec_len * size / 4) });
	cir5->setRefPoint({ RefPoint.x - int((config.Butterfly.circ1_rad - config.Butterfly.rec_width) * size), RefPoint.y + int(config.Butterfly.rec_len * size / 4) });
	cir3->setRefPoint({ RefPoint.x , RefPoint.y - int(config.Butterfly.rec_len* size / 2) });
	
	//draw();
}
void Butterfly::ResizeDown() {

	stepsCounter += 1;

	cir1->ResizeDown();
	cir2->ResizeDown();
	cir3->ResizeDown();
	cir4->ResizeDown();
	cir5->ResizeDown();
	rect->ResizeDown();

	size /= 2;
	cir1->setRefPoint({ RefPoint.x + int((config.Butterfly.circ1_rad - config.Butterfly.rec_width) * size), RefPoint.y - int(config.Butterfly.rec_len * size / 4) });
	cir4->setRefPoint({ RefPoint.x - int((config.Butterfly.circ1_rad - config.Butterfly.rec_width) * size), RefPoint.y - int(config.Butterfly.rec_len * size / 4) });
	cir2->setRefPoint({ RefPoint.x + int((config.Butterfly.circ1_rad - config.Butterfly.rec_width) * size), RefPoint.y + int(config.Butterfly.rec_len * size / 4) });
	cir5->setRefPoint({ RefPoint.x - int((config.Butterfly.circ1_rad - config.Butterfly.rec_width) * size), RefPoint.y + int(config.Butterfly.rec_len * size / 4) });
	cir3->setRefPoint({ RefPoint.x , RefPoint.y - int(config.Butterfly.rec_len * size / 2) });

	//draw();
}
void Butterfly::move(char step) {
	grid* pGrid = pGame->getGrid();
	int x1 = config.wx + 2*cir1->getrad();
	int x2 = config.wx + config.windWidth - 2.5* cir1->getrad();
	int y1 = config.wy + config.toolBarHeight + 2 * cir1->getrad();
	int y2 = config.wy + config.windHeight - config.statusBarHeight - 2 * cir1->getrad();

	stepsCounter += 1;

	if (step == 8 && RefPoint.y>y1)
	{
		RefPoint.y = RefPoint.y - config.gridSpacing;
		pGrid->deleteShape();
		cir2->move(step);
		cir5->move(step);
		cir1->move(step);
		cir4->move(step);
		cir3->move(step);
		rect->move(step);
		draw();
	}
	else if (step==2 && RefPoint.y <y2)
	{
		RefPoint.y = RefPoint.y + config.gridSpacing;
		pGrid->deleteShape();
		cir2->move(step);
		cir5->move(step);
		cir1->move(step);
		cir4->move(step);
		cir3->move(step);
		rect->move(step);
		draw();
	}
	else if (step==6 && RefPoint.x < x2)
	{
		RefPoint.x = RefPoint.x + config.gridSpacing;
		pGrid->deleteShape();
		cir2->move(step);
		cir5->move(step);
		cir1->move(step);
		cir4->move(step);
		cir3->move(step);
		rect->move(step);
		draw();
	}
	else if (step == 4 && RefPoint.x > x1)
	{
		RefPoint.x = RefPoint.x - config.gridSpacing;
		pGrid->deleteShape();
		cir2->move(step);
		cir5->move(step);
		cir1->move(step);
		cir4->move(step);
		cir3->move(step);
		rect->move(step);
		draw();
	}
	
}

void Butterfly::VerticalFlip() {

	stepsCounter += 1;

	cir1->setRefPoint({ RefPoint.x + config.Butterfly.circ1_rad - config.Butterfly.rec_width, RefPoint.y - config.Butterfly.rec_len / 4 });
	cir4->setRefPoint({ RefPoint.x - config.Butterfly.circ1_rad + config.Butterfly.rec_width, RefPoint.y + config.Butterfly.rec_len / 4 });
	cir2->setRefPoint({ RefPoint.x + config.Butterfly.circ1_rad - config.Butterfly.rec_width, RefPoint.y - config.Butterfly.rec_len / 4 });
	cir5->setRefPoint({ RefPoint.x - config.Butterfly.circ1_rad + config.Butterfly.rec_width, RefPoint.y - config.Butterfly.rec_len / 4 });
	cir3->setRefPoint({ RefPoint.x , RefPoint.y + config.Butterfly.rec_len / 2 });
	rect->VerticalFlip();
}

void Butterfly::rotate(int angle)
{
	switch (angle)
	{
	case 90:
		cir1->setRefPoint({ RefPoint.x + config.Butterfly.rec_len / 4 ,RefPoint.y + config.Butterfly.circ1_rad - config.Butterfly.rec_width });
		cir2->setRefPoint({ RefPoint.x - config.Butterfly.rec_len / 4 ,RefPoint.y + config.Butterfly.circ1_rad - config.Butterfly.rec_width });
		cir3->setRefPoint({ RefPoint.x + config.Butterfly.rec_len / 2, RefPoint.y });
		cir4->setRefPoint({ RefPoint.x + config.Butterfly.rec_len / 4 , RefPoint.y - config.Butterfly.circ1_rad + config.Butterfly.rec_width });
		cir5->setRefPoint({ RefPoint.x - config.Butterfly.rec_len / 4, RefPoint.y - config.Butterfly.circ1_rad + config.Butterfly.rec_width });
		rect->rotate(90);
		break;
	case 180:
		cir1->setRefPoint({ RefPoint.x + config.Butterfly.circ1_rad - config.Butterfly.rec_width, RefPoint.y - config.Butterfly.rec_len / 4 });
		cir2->setRefPoint({ RefPoint.x + config.Butterfly.circ1_rad - config.Butterfly.rec_width, RefPoint.y + config.Butterfly.rec_len / 4 });
		cir3->setRefPoint({ RefPoint.x, RefPoint.y + config.Butterfly.rec_len / 2 });
		cir4->setRefPoint({ RefPoint.x - config.Butterfly.circ1_rad + config.Butterfly.rec_width, RefPoint.y - config.Butterfly.rec_len / 4 });
		cir5->setRefPoint({ RefPoint.x - config.Butterfly.circ1_rad + config.Butterfly.rec_width, RefPoint.y + config.Butterfly.rec_len / 4 });

		break;
	case 270:
		cir1->setRefPoint({ RefPoint.x - config.Butterfly.rec_len / 4 , RefPoint.y - config.Butterfly.circ1_rad + config.Butterfly.rec_width });
		cir2->setRefPoint({ RefPoint.x + config.Butterfly.rec_len / 4, RefPoint.y - config.Butterfly.circ1_rad + config.Butterfly.rec_width });
		cir3->setRefPoint({ RefPoint.x - config.Butterfly.rec_len / 2, RefPoint.y });
		cir4->setRefPoint({ RefPoint.x - config.Butterfly.rec_len / 4 ,RefPoint.y + config.Butterfly.circ1_rad - config.Butterfly.rec_width });
		cir5->setRefPoint({ RefPoint.x + config.Butterfly.rec_len / 4 ,RefPoint.y + config.Butterfly.circ1_rad - config.Butterfly.rec_width });
		rect->rotate(90);
		break;

	default:
		break;
	}

}




string Butterfly::MyType() {
	return "Butterfly";
}


               //////////////////////////////class Home///////////////////////////////

Home::Home(game* r_pGame, point ref) :shape(pGame, ref)
{
	point refBaseRec = ref;
	point refTopTri = { ref.x - config.Home.wdth / 2,ref.y - config.Home.hght / 2 };
	point refTopRec = { refTopTri.x + config.Home.wdth2 / 2,ref.y - config.Home.hght2 / 2 };
	Tri = new Triangle(r_pGame, config.Home.t_Len, refTopTri);
	base = new Rect(r_pGame, refBaseRec, config.Home.hght, config.Home.wdth);
	top = new Rect(r_pGame, refTopRec, config.Home.hght2, config.Home.wdth2);
}
Home::~Home() {
	delete Tri, base, top;
}

void Home::draw() const
{
	top->draw();
	base->draw();
	Tri->draw();
}




void Home::ResizeUp() {

	stepsCounter += 1;

	if (size >= 2)
		return;

	Tri->ResizeUp();
	base->ResizeUp();
	top->ResizeUp();

	size *= 2;
	Tri->setRefPoint( {RefPoint.x - int(config.Home.wdth *size/ 2),RefPoint.y - int(config.Home.hght / 2 * size )});
	top->setRefPoint({ RefPoint.x - int(config.Home.wdth * size / 2),RefPoint.y - int(config.Home.hght / 2 * size )});

	//draw();
}
void Home::ResizeDown() {

	stepsCounter += 1;

	Tri->ResizeDown();
	base->ResizeDown();
	top->ResizeDown();

	size /= 2;
	Tri->setRefPoint({ RefPoint.x - int(config.Home.wdth * size / 2),RefPoint.y - int(config.Home.hght / 2 * size) });
	top->setRefPoint({ RefPoint.x - int(config.Home.wdth * size / 2),RefPoint.y - int(config.Home.hght / 2 * size) });

	//draw();
}

void Home::move(char step) {
	grid* pGrid = pGame->getGrid();
	int x1 = config.wx + Tri->getlength();
	int x2 = config.wx + config.windWidth - Tri->getlength();
	int y1 = config.wy + config.toolBarHeight + 2 * base->gethght();
	int y2 = config.wy + config.windHeight - config.statusBarHeight - 2* base->gethght();

	stepsCounter += 1;

	if (step == 8 && RefPoint.y > y1)
	{
		RefPoint.y = RefPoint.y - config.gridSpacing;
		pGrid->deleteShape();
		top->move(step);
		base->move(step);
		Tri->move(step);
		draw();
	}
	else if (step==2&& RefPoint.y < y2)
	{
		RefPoint.y = RefPoint.y + config.gridSpacing;
		pGrid->deleteShape();
		top->move(step);
		base->move(step);
		Tri->move(step);
		draw();
	}
	else if (step==6 && RefPoint.x <x2)
	{
		RefPoint.x = RefPoint.x + config.gridSpacing;
		pGrid->deleteShape();
		top->move(step);
		base->move(step);
		Tri->move(step);
		draw();
	}
	else if (step==4 && RefPoint.x > x1)
	{
		RefPoint.x = RefPoint.x - config.gridSpacing;
		pGrid->deleteShape();
		top->move(step);
		base->move(step);
		Tri->move(step);
		draw();
	}

}
void Home::VerticalFlip() {

	stepsCounter += 1;

	Tri->setRefPoint({ RefPoint.x - config.Home.wdth / 2,RefPoint.y + config.Home.hght / 2 });
	top->setRefPoint({ RefPoint.x - config.Home.wdth / 2,RefPoint.y + config.Home.hght / 2});
	Tri->VerticalFlip();
	top->VerticalFlip();
	base->VerticalFlip();
}
void Home::rotate(int angle)
{
	switch (angle)
	{
	case 90:
		Tri->setRefPoint({ RefPoint.x + config.Home.wdth / 2,RefPoint.y - config.Home.hght / 2 });
		top->setRefPoint({ RefPoint.x + config.Home.hght / 2 + config.Home.hght2 / 2,RefPoint.y - config.Home.hght / 2 + config.Home.wdth2 / 2 });
		base->rotate(90);
		Tri->rotate(90);
		top->rotate(90);
		break;
	case 180:
		Tri->setRefPoint({ RefPoint.x + config.Home.wdth / 2,RefPoint.y + config.Home.hght / 2 });
		top->setRefPoint({ RefPoint.x + config.Home.hght / 2 - config.Home.hght2 / 2,RefPoint.y + config.Home.hght / 2 + config.Home.wdth2 / 2 });
		base->rotate(180);
		Tri->rotate(180);
		top->rotate(180);
		break;
	case 270:
		Tri->setRefPoint({ RefPoint.x - config.Home.wdth / 2,RefPoint.y + config.Home.hght / 2 });
		top->setRefPoint({ RefPoint.x - config.Home.hght / 2 - config.Home.hght2 / 2,RefPoint.y + config.Home.hght / 2 - config.Home.wdth2 / 2 });
		base->rotate(270);
		Tri->rotate(270);
		top->rotate(270);
		break;
	default:
		break;
	}
}

string Home::MyType() {
	return "Home";
}

         ///////////////////////////////class Cat///////////////////////////////

Cat::Cat(game* r_pGame, point ref) :shape(pGame, ref)
{
	point refFace = ref;
	point refbody = { ref.x -config.Cat.len1/2,ref.y+((config.Cat.hght)/2+ (config.Cat.len1 * cos(3.14 / 3))) };
	point refEar1 = { ref.x - config.Cat.base / 2,ref.y - config.Cat.hght / 2 };
	point refEar2 = { ref.x + config.Cat.base /2 -config.Cat.len2,ref.y - config.Cat.hght / 2 };
	point refC1 = { ref.x - config.Cat.len1 / 2 ,ref.y + ((config.Cat.hght) / 2 + (config.Cat.len1 * cos(3.14 / 3))) };
	point refC2 = { ref.x + config.Cat.len1 / 2 ,ref.y + ((config.Cat.hght) / 2 + (config.Cat.len1 * cos(3.14 / 3))) };
	//face = new Rect(pGame, refFace, config.Cat.hght, config.Cat.base);
	face = new Rect(r_pGame, refFace, config.Cat.hght, config.Cat.base); 
	body = new Triangle(r_pGame, config.Cat.len1, refbody);
	ear1 = new Triangle(r_pGame, config.Cat.len2, refEar1);
	ear2 = new Triangle(r_pGame ,config.Cat.len2, refEar2);
	lFoot = new circle(r_pGame, refC1, config.Cat.rad);
	rFoot = new circle(r_pGame, refC2, config.Cat.rad);
}

Cat::~Cat() {
	delete face, body, ear1, ear2, lFoot, rFoot;
}

void Cat::draw() const
{
	body->draw();
	face->draw();
	ear1->draw();
	ear2->draw();
	lFoot->draw();
	rFoot->draw();
}
void Cat::ResizeUp() {
	
	stepsCounter += 1;

	if (size >= 2)
		return;

	body->ResizeUp();
	face->ResizeUp();
	ear1->ResizeUp();
	ear2->ResizeUp();
	lFoot->ResizeUp();
	rFoot->ResizeUp();
	size *= 2;
	body->setRefPoint({ RefPoint.x - int(config.Cat.len1 / 2 * size ), RefPoint.y + int(((config.Cat.hght) / 2 + (config.Cat.len1 * cos(3.14 / 3)) )* size) });
	ear1->setRefPoint({ RefPoint.x - int(config.Cat.base / 2 * size ),RefPoint.y - int(config.Cat.hght / 2 * size )});
	ear2->setRefPoint({ RefPoint.x + int((config.Cat.base / 2 - config.Cat.len2) * size ),RefPoint.y - int(config.Cat.hght / 2 * size )});
	lFoot->setRefPoint({ RefPoint.x - int(config.Cat.len1 / 2 * size ),RefPoint.y + int(((config.Cat.hght) / 2 + (config.Cat.len1 * cos(3.14 / 3))) * size )});
	rFoot->setRefPoint({ RefPoint.x + int(config.Cat.len1 / 2 * size ),RefPoint.y + int(((config.Cat.hght) / 2 + (config.Cat.len1 * cos(3.14 / 3))) * size )});

	//draw();
}
void Cat::ResizeDown() {

	stepsCounter += 1;

	body->ResizeDown();
	face->ResizeDown();
	ear1->ResizeDown();
	ear2->ResizeDown();
	lFoot->ResizeDown();
	rFoot->ResizeDown();

	size /= 2;
	body->setRefPoint({ RefPoint.x - int(config.Cat.len1 / 2 * size), RefPoint.y + int(((config.Cat.hght) / 2 + (config.Cat.len1 * cos(3.14 / 3))) * size) });
	ear1->setRefPoint({ RefPoint.x - int(config.Cat.base / 2 * size),RefPoint.y - int(config.Cat.hght / 2 * size) });
	ear2->setRefPoint({ RefPoint.x + int((config.Cat.base / 2 - config.Cat.len2) * size),RefPoint.y - int(config.Cat.hght / 2 * size) });
	lFoot->setRefPoint({ RefPoint.x - int(config.Cat.len1 / 2 * size),RefPoint.y + int(((config.Cat.hght) / 2 + (config.Cat.len1 * cos(3.14 / 3))) * size) });
	rFoot->setRefPoint({ RefPoint.x + int(config.Cat.len1 / 2 * size),RefPoint.y + int(((config.Cat.hght) / 2 + (config.Cat.len1 * cos(3.14 / 3))) * size) });

//	draw();
}
void Cat::move(char step) {
	grid* pGrid = pGame->getGrid();
	int x1 = config.wx + body->getlength();
	int x2 = config.wx + config.windWidth - body->getlength();
	int y1 = config.wy + config.toolBarHeight + face->gethght() + body->gethight();
	int y2 = config.wy + config.windHeight - config.statusBarHeight - body->gethight();
	
	stepsCounter += 1;

		if (step == 8 && RefPoint.y > y1)
		{
			RefPoint.y = RefPoint.y - config.gridSpacing;
			pGrid->deleteShape();
			body->move(step);
			face->move(step);
			ear1->move(step);
			ear2->move(step);
			lFoot->move(step);
			rFoot->move(step);
			draw();
		}
		else if (step == 2&& RefPoint.y < y2)
		{
			RefPoint.y = RefPoint.y + config.gridSpacing;
			pGrid->deleteShape();
			body->move(step);
			face->move(step);
			ear1->move(step);
			ear2->move(step);
			lFoot->move(step);
			rFoot->move(step);
			draw();
		}
		else if (step == 6 && RefPoint.x < x2)
		{
			RefPoint.x = RefPoint.x + config.gridSpacing;
			pGrid->deleteShape();
			body->move(step);
			face->move(step);
			ear1->move(step);
			ear2->move(step);
			lFoot->move(step);
			rFoot->move(step);
			draw();
		}
		else if (step == 4&&RefPoint.x >x1 )
		{
			RefPoint.x = RefPoint.x - config.gridSpacing;
			pGrid->deleteShape();
			body->move(step);
			face->move(step);
			ear1->move(step);
			ear2->move(step);
			lFoot->move(step);
			rFoot->move(step);
			draw();
		}
	

}
void Cat::VerticalFlip() {

	stepsCounter += 1;

	body->setRefPoint({ RefPoint.x - config.Cat.len1/2,RefPoint.y - int((config.Cat.hght) / 2 + (config.Cat.len1 * cos(3.14 / 3))) });
	ear1->setRefPoint({ RefPoint.x - config.Cat.base / 2,RefPoint.y + config.Cat.hght / 2 });
	ear2->setRefPoint( { RefPoint.x + config.Cat.base /2 - config.Cat.len2 ,RefPoint.y + config.Cat.hght / 2 });
	lFoot->setRefPoint( { RefPoint.x - config.Cat.len1 / 2 - config.Cat.rad , RefPoint.y - int((config.Cat.hght) / 2 + (config.Cat.len1 * cos(3.14 / 3))) });
	rFoot->setRefPoint({ RefPoint.x + config.Cat.len1 / 2 + config.Cat.rad,RefPoint.y - int((config.Cat.hght) / 2 + (config.Cat.len1 * cos(3.14 / 3))) });
	face->VerticalFlip();
	body->VerticalFlip();
	ear1->VerticalFlip();
	ear2->VerticalFlip();
}
void Cat::rotate(int angle)
{
	switch (angle)
	{
	case 90:
		body->rotate(90);
		ear1->rotate(90);
		ear2->rotate(90);
		body->setRefPoint({ int(RefPoint.x - config.Cat.len1 * cos(3.14 / 3)) ,RefPoint.y - config.Cat.base / 2 });
		ear1->setRefPoint({ RefPoint.x + config.Cat.base / 2,RefPoint.y - config.Cat.hght / 2 });
		ear2->setRefPoint({ RefPoint.x + config.Cat.base / 2 ,RefPoint.y + config.Cat.hght / 2 - config.Cat.len2 });
		lFoot->setRefPoint({ int(RefPoint.x - config.Cat.len1 * cos(3.14 / 3)) ,RefPoint.y - config.Cat.base / 2 });
		rFoot->setRefPoint({ int(RefPoint.x - config.Cat.len1 * cos(3.14 / 3)) ,RefPoint.y - config.Cat.base / 2 + config.Cat.len1 });
		break;
	case 180:
		body->rotate(90);
		ear1->rotate(90);
		ear2->rotate(90);
		body->setRefPoint({ RefPoint.x + config.Cat.base / 2, int(RefPoint.y - config.Cat.len1 * cos(3.14 / 3)) });
		ear1->setRefPoint({ RefPoint.x + config.Cat.base / 2,RefPoint.y + config.Cat.hght / 2 });
		ear2->setRefPoint({ RefPoint.x - config.Cat.base / 2 + config.Cat.len2 ,RefPoint.y + config.Cat.hght / 2 });
		lFoot->setRefPoint({ RefPoint.x + config.Cat.base / 2, int(RefPoint.y - config.Cat.len1 * cos(3.14 / 3)) });
		rFoot->setRefPoint({ RefPoint.x + config.Cat.base / 2 + config.Cat.len1, int(RefPoint.y - config.Cat.len1 * cos(3.14 / 3)) });

		break;
	case 270:
		body->rotate(270);
		ear1->rotate(270);
		ear2->rotate(270);
		body->setRefPoint({ int(RefPoint.x + config.Cat.len1 * cos(3.14 / 3)) ,RefPoint.y - config.Cat.base / 2 });
		ear1->setRefPoint({ RefPoint.x - config.Cat.base / 2,RefPoint.y - config.Cat.hght / 2 });
		ear2->setRefPoint({ RefPoint.x - config.Cat.base / 2 ,RefPoint.y + config.Cat.hght / 2 - config.Cat.len2 });
		lFoot->setRefPoint({ int(RefPoint.x + config.Cat.len1 * cos(3.14 / 3)) ,RefPoint.y - config.Cat.base / 2 });
		rFoot->setRefPoint({ int(RefPoint.x + config.Cat.len1 * cos(3.14 / 3)) ,RefPoint.y - config.Cat.base / 2 + config.Cat.len1 });
		break;

	default:
		break;
	}
}


string Cat::MyType() {
	return "Cat";
}


                 ////////////////////////////////class car////////////////////////

car::car(game* r_pGame, point ref) :shape(r_pGame, ref)
{
	point rectRef = ref;
	point triRef = { ref.x + config.car.len / 2 - config.car.len2 ,ref.y - config.car.hght / 2 };
	point cir1 = { ref.x + config.car.len / 2 - config.car.rad,ref.y + config.car.hght / 2 + config.car.rad };
	point cir2 = { ref.x - config.car.len / 2 + config.car.rad,ref.y + config.car.hght / 2 + config.car.rad };
	body = new Rect(r_pGame, rectRef, config.car.hght, config.car.len);
	top = new Triangle(r_pGame, config.car.len2, triRef);
	whl1 = new circle(r_pGame, cir1, config.car.rad);
	whl2 = new circle(r_pGame, cir2, config.car.rad);
}

car::~car() {
	delete body, top, whl1, whl2;
}

void car::draw() const
{
	body->draw();
	top->draw();
	whl1->draw();
	whl2->draw();
}
void car::ResizeUp() {

	stepsCounter += 1;

	if (size >= 4)
		return;

	body->ResizeUp();
	top->ResizeUp();
	whl1->ResizeUp();
	whl2->ResizeUp();

	size *=2;
	top->setRefPoint({ RefPoint.x + int((config.car.len / 2 -config.car.len2)*size),RefPoint.y - int((config.car.hght / 2) *size )});
	whl1->setRefPoint( { RefPoint.x + int((config.car.len / 2  - config.car.rad) * size),RefPoint.y + int((config.car.hght / 2 + config.car.rad) * size) });
	whl2->setRefPoint({ RefPoint.x - int((config.car.len / 2 - config.car.rad) * size),RefPoint.y + int((config.car.hght / 2 + config.car.rad ) * size )});

	//draw();
}
void car::ResizeDown() {

	stepsCounter += 1;

	body->ResizeDown();
	top->ResizeDown();
	whl1->ResizeDown();
	whl2->ResizeDown();

	size /= 2;
	top->setRefPoint({ RefPoint.x + int((config.car.len / 2 - config.car.len2) * size),RefPoint.y - int((config.car.hght / 2) * size) });
	whl1->setRefPoint({ RefPoint.x + int((config.car.len / 2 - config.car.rad) * size),RefPoint.y + int((config.car.hght / 2 + config.car.rad) * size) });
	whl2->setRefPoint({ RefPoint.x - int((config.car.len / 2 - config.car.rad) * size),RefPoint.y + int((config.car.hght / 2 + config.car.rad) * size) });

	//draw();
}
void car::move(char step){

	grid* pGrid = pGame->getGrid();
	int x1 = config.wx + body->getwdth();
	int x2 = config.wx + config.windWidth - body->getwdth();
	int y1 = config.wy + config.toolBarHeight + 1.4*body->gethght() + top->gethight();
	int y2 = config.wy + config.windHeight - config.statusBarHeight - whl1 ->getrad() - 1.4*body->gethght();
	
	stepsCounter += 1;

	if (step == 8 && RefPoint.y > y1)
	{
		RefPoint.y = RefPoint.y - config.gridSpacing;
		pGrid->deleteShape();
		body->move(step);
		top->move(step);
		whl1->move(step);
		whl2->move(step);
		draw();
	}
	else if (step == 2 && RefPoint.y < y2)
	{
		RefPoint.y = RefPoint.y + config.gridSpacing;
		pGrid->deleteShape();
		body->move(step);
		top->move(step);
		whl1->move(step);
		whl2->move(step);
		draw();
	}
	else if (step == 6 && RefPoint.x < x2)
	{
		RefPoint.x = RefPoint.x + config.gridSpacing;
		pGrid->deleteShape();
		body->move(step);
		top->move(step);
		whl1->move(step);
		whl2->move(step);
		draw();
	}
	else if (step == 4 && RefPoint.x > x1)
	{
		RefPoint.x = RefPoint.x - config.gridSpacing;
		pGrid->deleteShape();
		body->move(step);
		top->move(step);
		whl1->move(step);
		whl2->move(step);
		draw();
	}
	
}
void car::rotate(int angle)
{
	switch (angle)
	{
	case 90:
		body->rotate(90);
		top->rotate(90);
		top->setRefPoint({ RefPoint.x + config.car.len / 2 ,RefPoint.y + config.car.hght / 2 - config.car.len2 });
		whl2->setRefPoint({ RefPoint.x - config.car.len / 2 , RefPoint.y + config.car.hght / 2 - config.car.rad });
		whl2->setRefPoint({ RefPoint.x - config.car.len / 2 , RefPoint.y - config.car.hght / 2 + config.car.rad });
		whl2->draw();
		whl1->draw();
		break;
	case 180:
		body->rotate(180);
		top->rotate(180);
		top->setRefPoint({ RefPoint.x + config.car.len / 2 - config.car.len2 ,RefPoint.y - config.car.hght / 2 });
		whl2->setRefPoint({ RefPoint.x - config.car.len / 2 + config.car.rad,RefPoint.y - config.car.hght / 2 - config.car.rad });
		whl2->setRefPoint({ RefPoint.x + config.car.len / 2 - config.car.rad,RefPoint.y - config.car.hght / 2 - config.car.rad });
		whl2->draw();
		whl1->draw();
		break;
	case 270:
		body->rotate(270);
		top->rotate(270);
		top->setRefPoint({ RefPoint.x - config.car.len / 2 ,RefPoint.y + config.car.hght / 2 - config.car.len2 });
		whl2->setRefPoint({ RefPoint.x + config.car.len / 2 , RefPoint.y + config.car.hght / 2 - config.car.rad });
		whl2->setRefPoint({ RefPoint.x + config.car.len / 2 , RefPoint.y - config.car.hght / 2 + config.car.rad });
		whl2->draw();
		whl1->draw();
		break;

	default:
		break;
	}
}

void car::VerticalFlip() {}


string car::MyType() {
	return "car";
}