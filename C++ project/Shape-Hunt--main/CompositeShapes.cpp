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



/////////////////////////calss Tree/////////////

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


