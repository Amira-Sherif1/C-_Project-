#include "BasicShapes.h"
#include "gameConfig.h"
#include "game.h"

////////////////////////////////////////////////////  class Rect  ///////////////////////////////////////

Rect::Rect(game* r_pGame, point ref, int r_hght, int r_wdth):shape(r_pGame,ref)
{
	pGame = r_pGame;
	hght = r_hght;
	wdth = r_wdth;
}

void Rect::draw() const
{
	window* pW = pGame->getWind();	//get interface window
	pW->SetPen(config.penColor, config.penWidth);
	pW->SetBrush(config.fillColor);
	point upperLeft, lowerBottom;
	upperLeft.x = RefPoint.x - wdth / 2;
	upperLeft.y = RefPoint.y - hght / 2;
	lowerBottom.x = RefPoint.x + wdth / 2;
	lowerBottom.y = RefPoint.y + hght / 2;

	pW->DrawRectangle(upperLeft.x, upperLeft.y, lowerBottom.x, lowerBottom.y, FILLED);
}
/*void Rect::ResizeUp()
{
	hght *= 2;
	wdth *= 2;
	draw();
}
void Rect::ResizeDown()
{
	hght /= 2;
	wdth /= 2;
	draw();
}
*/

////////////////////////////////////////////////////  class circle  ///////////////////////////////////////
//TODO: Add implementation for class circle here
circle::circle(game* r_pGame, point ref, int r):shape(r_pGame,ref)
{
	rad = r;
}

void circle::draw() const
{
	window* pW = pGame->getWind();	//get interface window
	pW->SetPen(borderColor, config.penWidth);
	pW->SetBrush(fillColor);
	pW->DrawCircle(RefPoint.x, RefPoint.y, rad, FILLED);
}
/*void circle::ResizeUp() {
	rad *= 2;
	draw();
}

void circle::ResizeDown() {
	rad /= 2;
	draw();
}
*/

////////////////////////////////////////////////////  class triangle  ///////////////////////////////////////
//TODO: Add implementation for class triangle here
Triangle::Triangle(game* r_pgame,int len, point ref) : shape(r_pgame, ref) {
	length = len;
	hight = len*cos(3.14/3);
};

void Triangle::draw()const {
	window* pW = pGame->getWind();
	pW->SetPen(config.penColor, config.penWidth);
	pW->SetBrush(config.fillColor);
	point p1, p2, p3;
	p1.x = RefPoint.x;
	p1.y = RefPoint.y;
	p2.x = RefPoint.x + length;
	p2.y = RefPoint.y;
	p3.x = RefPoint.x + length / 2;
	p3.y = RefPoint.y - hight;
	pW->DrawTriangle(p1.x, p1.y, p2.x, p2.y,p3.x,p3.y,FILLED);
}
/*void Triangle::ResizeUp() {
	length *= 2;
	hight *= 2;
	draw();
}
void Triangle::ResizeDown() {
	length /= 2;
	hight /= 2;
	draw();
}*/