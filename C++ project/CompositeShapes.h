#pragma once
#include "Basicshapes.h"


////////////////////////////////////////////////////  class Sign  ///////////////////////////////////////
//This class reprsents the composite shape "sign"
//The sign is composed of 2 Recatngles
/*				

					 ------------------
					|				   |
					|		 x		   |     x is the reference point of the Sign shape
					|			       |
					 ------------------
						   |   |
						   |   |
						   | . |
						   |   |
						   |   |
							---
*/

//Note: sign reference point is the center point of the top rectangle
class Sign :public shape
{
	Rect* base;
	Rect* top;
public:
	Sign(game* r_pGame, point ref);
	virtual void draw() const;

	virtual void ResizeUp();
	virtual void ResizeDown();

	virtual void VerticalFlip();

	virtual void move(char step);

};
class Tree : public shape {
	Rect* root;
	Triangle* T1;
	Triangle* T2;
	Triangle* T3;
	Triangle* T4;
public:
	Tree(game* r_pGame, point ref);
	virtual void draw() const;
	virtual void ResizeUp();
	virtual void ResizeDown();

	virtual void VerticalFlip();

	virtual void move(char step);

};
class Boat :public shape {
	Rect* rect1;
	Rect* rect2;
	Triangle* T1;
	Triangle* T2;
	Triangle* T3;

public:
	Boat(game* r_pgame, point ref);
	virtual void draw() const;
	virtual void ResizeUp();
	virtual void ResizeDown();
	virtual void VerticalFlip();
	virtual void move(char step);
};

class Butterfly : public shape {
	circle* cir1;
	circle* cir2;
	circle* cir3;
	circle* cir4; 
	circle* cir5; 
	Rect* rect;

public:
	Butterfly(game* r_pgame, point ref);
	virtual void draw()const;
	virtual void ResizeUp();
	virtual void ResizeDown();
	virtual void VerticalFlip();
	virtual void move(char step);
};

                  
class Cone :public shape
{
	circle* top;
	Triangle* base;
public:
	Cone(game* r_pGame, point ref);
	virtual void draw() const;
	//virtual void rotate();
	virtual void ResizeUp();
	virtual void ResizeDown();
	virtual void VerticalFlip();
	virtual void move(char step);
};


class Home :public shape
{
	Triangle* Tri;
	Rect* base;
	Rect* top;
public:
	Home(game* r_pGame, point ref);
	virtual void draw() const;
	virtual void ResizeUp();
	virtual void ResizeDown();
	virtual void VerticalFlip();
	virtual void move(char step);
};



class Cat :public shape
{
	Triangle* body;
	Triangle* ear1;
	Triangle* ear2;
	circle* lFoot;
	circle* rFoot;
	Rect* face;

public:
	Cat(game* r_pGame, point ref);
	virtual void draw() const;
	virtual void ResizeUp();
	virtual void ResizeDown();
	virtual void VerticalFlip();
	virtual void move(char step);
};

