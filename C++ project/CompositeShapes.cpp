#include "CompositeShapes.h"
#include "gameConfig.h"

////////////////////////////////////////////////////  class Sign  ///////////////////////////////////////
Sign::Sign(game* r_pGame, point ref):shape(r_pGame, ref)
{
	//calc the ref point of the Sign base and top rectangles relative to the Sign shape
	point topRef = ref;	//top rect ref is the same as the sign
	point baseRef = { ref.x, ref.y + config.sighShape.topHeight / 2 + config.sighShape.baseHeight / 2 };
	top = new Rect(pGame, topRef, config.sighShape.topHeight, config.sighShape.topWdth);
	base = new Rect(pGame, baseRef, config.sighShape.baseHeight, config.sighShape.baseWdth);
}

void Sign::draw() const
{
	base->draw();
	top->draw();
}

/*void Sign::ResizeUp() {
	base->ResizeUp();
	top->ResizeUp();
	top->setRefPoint({ RefPoint.x,RefPoint.y +(config.sighShape.topHeight / 2 + config.sighShape.baseHeight / 2) * 2 });
<<<<<<< Updated upstream
}*/





void Sign::ResizeDown(){
	base->ResizeDown();
	top->ResizeDown();
	top->setRefPoint({ RefPoint.x,RefPoint.y +( config.sighShape.topHeight / 2 + config.sighShape.baseHeight / 2) / 2 });
}

void Sign::ResizeUp() {
	config.sighShape.baseHeight *= 2;
	config.sighShape.baseWdth *= 2;
	config.sighShape.topHeight *= 2;
	config.sighShape.topWdth *= 2;
	//top = new Rect();
}
void Sign::move(char step) {
	if (step == 72)
	{
		RefPoint.y = RefPoint.y - config.gridSpacing;
	}
	if (step == 80)
	{
		RefPoint.y = RefPoint.y + config.gridSpacing;
	}
	if (step == 77)
	{
		RefPoint.x = RefPoint.x + config.gridSpacing;
	}
	if (step == 75)
	{
		RefPoint.x = RefPoint.x - config.gridSpacing;
	}
	base->move(step);
	top->move(step);
	draw();
}
void Sign::VerticalFlip() {
	base->setRefPoint( { RefPoint.x, RefPoint.y -( config.sighShape.topHeight / 2 + config.sighShape.baseHeight / 2 )});
	base->VerticalFlip();
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
void Tree::draw() const
{
	T1->draw();
	T2->draw();
	T3->draw();
	T4->draw();
	root->draw();
}
void Tree::ResizeUp(){
	root->ResizeUp();
	T1->ResizeUp();
	T2->ResizeUp();
	T3->ResizeUp();
	T4->ResizeUp();
	T2->setRefPoint ( { RefPoint.x - config.Tree.trilen /2,RefPoint.y - config.Tree.trihigh *1 / 3 });
	T3->setRefPoint ( { RefPoint.x - config.Tree.trilen /2 ,RefPoint.y - config.Tree.trihigh * 2 / 3 });
	T4->setRefPoint ( { RefPoint.x - config.Tree.trilen /2,RefPoint.y - config.Tree.trihigh * 1 });
	root->setRefPoint({ RefPoint.x,RefPoint.y + config.Tree.recthight });
}
void Tree::ResizeDown() {
	root->ResizeDown();
	T1->ResizeDown();
	T2->ResizeDown();
	T3->ResizeDown();
	T4->ResizeDown();
	T1->setRefPoint({ RefPoint.x - config.Tree.trilen /4,RefPoint.y });
	T2->setRefPoint({ RefPoint.x - config.Tree.trilen /4,RefPoint.y - config.Tree.trihigh * 1 / 6 });
	T3->setRefPoint({ RefPoint.x - config.Tree.trilen /4,RefPoint.y - config.Tree.trihigh * 1 / 3 });
	T4->setRefPoint({ RefPoint.x - config.Tree.trilen /4,RefPoint.y - config.Tree.trihigh / 2 });
	root->setRefPoint({ RefPoint.x,RefPoint.y + config.Tree.recthight/4 });
}
void Tree::move(char step) {
	if (step == 72)
	{
		RefPoint.y = RefPoint.y - config.gridSpacing;
	}
	if (step == 80)
	{
		RefPoint.y = RefPoint.y + config.gridSpacing;
	}
	if (step == 77)
	{
		RefPoint.x = RefPoint.x + config.gridSpacing;
	}
	if (step == 75)
	{
		RefPoint.x = RefPoint.x - config.gridSpacing;
	}
	T1->move(step);
	T2->move(step);
	T3->move(step);
	T4->move(step);
	root->move(step);
	draw();
}
void Tree::VerticalFlip() {
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
void Butterfly::draw() const{
	cir2->draw();
	cir5->draw();
	cir1->draw();
	cir4->draw();
	cir3->draw();
	rect->draw();
}
void Butterfly::ResizeUp(){
	cir1->ResizeUp();
	cir2->ResizeUp();
	cir3->ResizeUp();
	cir4->ResizeUp();
	cir5->ResizeUp();
	rect->ResizeUp();
	cir1->setRefPoint({ RefPoint.x + config.Butterfly.circ1_rad - config.Butterfly.rec_width, RefPoint.y + config.Butterfly.rec_len / 4 });
	cir4->setRefPoint({ RefPoint.x - config.Butterfly.circ1_rad + config.Butterfly.rec_width, RefPoint.y + config.Butterfly.rec_len / 4 });
	cir2->setRefPoint({ RefPoint.x + config.Butterfly.circ1_rad - config.Butterfly.rec_width, RefPoint.y - config.Butterfly.rec_len / 4 });
	cir5->setRefPoint({ RefPoint.x - config.Butterfly.circ1_rad + config.Butterfly.rec_width, RefPoint.y - config.Butterfly.rec_len / 4 });
	cir3->setRefPoint({ RefPoint.x , RefPoint.y + config.Butterfly.rec_len / 2 });
}
void Butterfly::ResizeDown() {
	cir1->ResizeDown();
	cir2->ResizeDown();
	cir3->ResizeDown();
	cir4->ResizeDown();
	cir5->ResizeDown();
	rect->ResizeDown();
	cir1->setRefPoint({ RefPoint.x + config.Butterfly.circ1_rad - config.Butterfly.rec_width, RefPoint.y + config.Butterfly.rec_len / 4 });
	cir4->setRefPoint({ RefPoint.x - config.Butterfly.circ1_rad + config.Butterfly.rec_width, RefPoint.y + config.Butterfly.rec_len / 4 });
	cir2->setRefPoint({ RefPoint.x + config.Butterfly.circ1_rad - config.Butterfly.rec_width, RefPoint.y - config.Butterfly.rec_len / 4 });
	cir5->setRefPoint({ RefPoint.x - config.Butterfly.circ1_rad + config.Butterfly.rec_width, RefPoint.y - config.Butterfly.rec_len / 4 });
	cir3->setRefPoint({ RefPoint.x , RefPoint.y + config.Butterfly.rec_len / 2 });
}
void Butterfly::move(char step) {
	if (step == 72)
	{
		RefPoint.y = RefPoint.y - config.gridSpacing;
	}
	if (step == 80)
	{
		RefPoint.y = RefPoint.y + config.gridSpacing;
	}
	if (step == 77)
	{
		RefPoint.x = RefPoint.x + config.gridSpacing;
	}
	if (step == 75)
	{
		RefPoint.x = RefPoint.x - config.gridSpacing;
	}
	cir2->move(step);
	cir5->move(step);
	cir1->move(step);
	cir4->move(step);
	cir3->move(step);
	rect->move(step);
	draw();
}
void Butterfly::VerticalFlip() {
	cir1->setRefPoint({ RefPoint.x + config.Butterfly.circ1_rad - config.Butterfly.rec_width, RefPoint.y - config.Butterfly.rec_len / 4 });
	cir4->setRefPoint({ RefPoint.x - config.Butterfly.circ1_rad + config.Butterfly.rec_width, RefPoint.y + config.Butterfly.rec_len / 4 });
	cir2->setRefPoint({ RefPoint.x + config.Butterfly.circ1_rad - config.Butterfly.rec_width, RefPoint.y - config.Butterfly.rec_len / 4 });
	cir5->setRefPoint({ RefPoint.x - config.Butterfly.circ1_rad + config.Butterfly.rec_width, RefPoint.y - config.Butterfly.rec_len / 4 });
	cir3->setRefPoint({ RefPoint.x , RefPoint.y + config.Butterfly.rec_len / 2 });
	rect->VerticalFlip();
}

                      ////////////////////////class cone//////////////////////////////////

Cone::Cone(game* r_pGame, point ref) :shape(pGame, ref)
{
	point refCirc = ref;
	point refTri = { ref.x - config.cone.length / 2,ref.y };
	top = new circle(r_pGame, ref, config.cone.radius);
	base = new Triangle(r_pGame, config.cone.length, refTri);
}


void Cone::draw() const
{
	top->draw();
	base->draw();
}

void Cone::ResizeUp() {}
void Cone::ResizeDown() {}
void Cone::move(char step) {
	if (step == 72)
	{
		RefPoint.y = RefPoint.y - config.gridSpacing;
	}
	if (step == 80)
	{
		RefPoint.y = RefPoint.y + config.gridSpacing;
	}
	if (step == 77)
	{
		RefPoint.x = RefPoint.x + config.gridSpacing;
	}
	if (step == 75)
	{
		RefPoint.x = RefPoint.x - config.gridSpacing;
	}
	top->move(step);
	base->move(step);
	draw();
}
void Cone::VerticalFlip() {
	base->setRefPoint({ RefPoint.x - config.cone.length / 2,RefPoint.y });
	base->VerticalFlip();
}


               //////////////////////////////class Home///////////////////////////////

Home::Home(game* r_pGame, point ref) :shape(pGame, ref)
{
	point refBaseRec = ref;
	point refTopTri = { ref.x - config.Home.wdth / 2,ref.y - config.Home.hght / 2 };
	point refTopRec = { ref.x - config.Home.wdth / 2,ref.y - config.Home.hght / 2 };
	Tri = new Triangle(r_pGame, config.Home.t_Len, refTopTri);
	base = new Rect(r_pGame, refBaseRec, config.Home.hght, config.Home.wdth);
	top = new Rect(r_pGame, refTopRec, config.Home.hght2, config.Home.wdth2);
}

void Home::draw() const
{
	top->draw();
	base->draw();
	Tri->draw();
}
void Home::ResizeUp() {}
void Home::ResizeDown() {}
void Home::move(char step) {
	if (step == 72)
	{
		RefPoint.y = RefPoint.y - config.gridSpacing;
	}
	if (step == 80)
	{
		RefPoint.y = RefPoint.y + config.gridSpacing;
	}
	if (step == 77)
	{
		RefPoint.x = RefPoint.x + config.gridSpacing;
	}
	if (step == 75)
	{
		RefPoint.x = RefPoint.x - config.gridSpacing;
	}
	top->move(step);
	base->move(step);
	Tri->move(step);
	
	draw();
}
void Home::VerticalFlip() {
	Tri->setRefPoint({ RefPoint.x - config.Home.wdth / 2,RefPoint.y + config.Home.hght / 2 });
	top->setRefPoint({ RefPoint.x - config.Home.wdth / 2,RefPoint.y + config.Home.hght / 2});
	Tri->VerticalFlip();
	top->VerticalFlip();
	base->VerticalFlip();
}


         ///////////////////////////////class Cat///////////////////////////////

Cat::Cat(game* r_pGame, point ref) :shape(pGame, ref)
{
	point refFace = ref;

	point refbody = { ref.x- config.Cat.len1,ref.y+((config.Cat.hght)/2+ (config.Cat.len1 * cos(3.14 / 3))) };
	point refEar1 = { ref.x - config.Cat.base / 2,ref.y - config.Cat.hght / 2 };
	point refEar2 = { ref.x + config.Cat.base /2 -config.Cat.len2,ref.y - config.Cat.hght / 2 };
	point refC1 = { ref.x + config.Cat.base - config.Cat.rad/ 2,ref.y + ((config.Cat.hght) / 2 + (config.Cat.len1 * cos(3.14 / 3))) };
	point refC2 = { ref.x - config.Cat.base + config.Cat.rad / 2,ref.y + ((config.Cat.hght) / 2 + (config.Cat.len1 * cos(3.14 / 3))) };
	face = new Rect(pGame, refFace, config.Cat.hght, config.Cat.base);
	body = new Triangle(r_pGame, config.Cat.len1, refbody);
	ear1 = new Triangle(r_pGame, config.Cat.len2, refEar1);
	ear2 = new Triangle(r_pGame ,config.Cat.len2, refEar2);
	lFoot = new circle(r_pGame, refC1, config.Cat.rad);
	rFoot = new circle(r_pGame, refC2, config.Cat.rad);
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
void Cat::ResizeUp() {}
void Cat::ResizeDown() {}
void Cat::move(char step) {
	if (step == 72)
	{
		RefPoint.y = RefPoint.y - config.gridSpacing;
	}
	if (step == 80)
	{
		RefPoint.y = RefPoint.y + config.gridSpacing;
	}
	if (step == 77)
	{
		RefPoint.x = RefPoint.x + config.gridSpacing;
	}
	if (step == 75)
	{
		RefPoint.x = RefPoint.x - config.gridSpacing;
	}
	body->move(step);
	face->move(step);
	ear1->move(step);
	ear2->move(step);
	lFoot->move(step);
	rFoot->move(step);
	draw();
}
void Cat::VerticalFlip() {
	body->setRefPoint({ RefPoint.x - config.Cat.len1,RefPoint.y - int((config.Cat.hght) / 2 + (config.Cat.len1 * cos(3.14 / 3))) });
	ear1->setRefPoint({ RefPoint.x - config.Cat.base / 2,RefPoint.y + config.Cat.hght / 2 });
	ear2->setRefPoint( { RefPoint.x + config.Cat.base /2 - config.Cat.len2 ,RefPoint.y + config.Cat.hght / 2 });
	lFoot->setRefPoint( { RefPoint.x + config.Cat.base / 2 - config.Cat.rad , RefPoint.y - int((config.Cat.hght) / 2 + (config.Cat.len1 * cos(3.14 / 3))) });
	rFoot->setRefPoint({ RefPoint.x - config.Cat.base / 2 + config.Cat.rad,RefPoint.y - int((config.Cat.hght) / 2 + (config.Cat.len1 * cos(3.14 / 3))) });
	face->VerticalFlip();
	body->VerticalFlip();
	ear1->VerticalFlip();
	ear2->VerticalFlip();
}
