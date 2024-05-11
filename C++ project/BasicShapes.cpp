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
	//pW->SetPen(config.penColor, config.penWidth);
	//pW->SetBrush(config.fillColor);
	point upperLeft, lowerBottom;
	upperLeft.x = RefPoint.x - wdth / 2;
	upperLeft.y = RefPoint.y - hght / 2;
	lowerBottom.x = RefPoint.x + wdth / 2;
	lowerBottom.y = RefPoint.y + hght / 2;

	pW->DrawRectangle(upperLeft.x, upperLeft.y, lowerBottom.x, lowerBottom.y, FILLED);
}
void Rect::ResizeUp()
{
	hght *= 2;
	wdth *= 2;
	//draw();
}
void Rect::ResizeDown()
{
	hght /= 2;
	wdth /= 2;
	//draw();
}
int Rect::gethght()const {
	return hght;
}
int Rect::getwdth()const {
	return wdth;
}
 void Rect:: move(char step){
	 if (step == 8)
	 {
		 RefPoint.y = RefPoint.y - config.gridSpacing;
	 }
	 if (step==2)
	 {
		 RefPoint.y = RefPoint.y + config.gridSpacing;
	 }
	 if (step==6)
	 {
		 RefPoint.x = RefPoint.x + config.gridSpacing;
	 }
	 if (step==4)
	 {
		 RefPoint.x = RefPoint.x - config.gridSpacing;
	 }
 
 }
void Rect::rotate() {
	int uuu=hght;
	hght = wdth;
	wdth = uuu;
}
void Rect::VerticalFlip() {
	hght = hght * (-1);
}


////////////////////////////////////////////////////  class circle  ///////////////////////////////////////
//TODO: Add implementation for class circle here
circle::circle(game* r_pGame, point ref, int r):shape(r_pGame,ref)
{
	rad = r;
}

void circle::draw() const
{
	window* pW = pGame->getWind();	//get interface window
	//pW->SetPen(borderColor, config.penWidth);
	//pW->SetBrush(fillColor);
	pW->DrawCircle(RefPoint.x, RefPoint.y, rad, FILLED);
}
void circle::ResizeUp() {
	rad *= 2;
	//draw();
}

void circle::ResizeDown() {
	rad /= 2;
	//draw();
}
int circle::getrad()const {
	return rad;
}
void circle::move(char step) {

	if (step == 8)
	{
		RefPoint.y = RefPoint.y - config.gridSpacing;
	}
	if (step==2)
	{
		RefPoint.y = RefPoint.y + config.gridSpacing;
	}
	if (step==6)
	{
		RefPoint.x = RefPoint.x + config.gridSpacing;
	}
	if (step==4)
	{
		RefPoint.x = RefPoint.x - config.gridSpacing;
	}
}
void circle::rotate(){}

////////////////////////////////////////////////////  class triangle  ///////////////////////////////////////
//TODO: Add implementation for class triangle here
Triangle::Triangle(game* r_pgame,int len, point ref) : shape(r_pgame, ref) {
	length = len;
	hight = len*cos(3.14/3);
};

void Triangle::draw()const {
	window* pW = pGame->getWind();
	//pW->SetPen(config.penColor, config.penWidth);
	//pW->SetBrush(config.fillColor);
	point p1, p2, p3;
	p1.x = RefPoint.x;
	p1.y = RefPoint.y;
	p2.x = RefPoint.x + length;
	p2.y = RefPoint.y;
	p3.x = RefPoint.x + length / 2;
	p3.y = RefPoint.y - hight;
	pW->DrawTriangle(p1.x, p1.y, p2.x, p2.y,p3.x,p3.y,FILLED);
}
void Triangle::ResizeUp() {
	length *= 2;
	hight *= 2;
	//draw();
}
void Triangle::ResizeDown() {
	length /= 2;
	hight /= 2;
	//draw();
}
int Triangle::gethight()const {
	return hight;
}
int Triangle::getlength()const {
	return length;
}

void Triangle::move(char step) {

	if (step == 8)
	{
		RefPoint.y = RefPoint.y - config.gridSpacing;
	}
	if (step == 2)
	{
		RefPoint.y = RefPoint.y + config.gridSpacing;
	}
	if (step == 6)
	{
		RefPoint.x = RefPoint.x + config.gridSpacing;
	}
	if (step == 4)
	{
		RefPoint.x = RefPoint.x - config.gridSpacing;
	}
}

void Triangle::rotate() {
	int temp = length;
	length = hight;
	hight = temp;

	RefPoint.x = RefPoint.x - hight;
	RefPoint.y = RefPoint.y + length / 2;

}
void Triangle::VerticalFlip() {
	hight = (-1) * hight;
}