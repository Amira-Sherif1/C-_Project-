#include "shape.h"
#include "game.h"
#include "gameConfig.h"
#include<fstream>
shape::shape(game* r_pGame, point ref)
{
	RefPoint = ref;
	pGame = r_pGame;
	fillColor = config.fillColor;
	//borderColor = config.penColor;
}

void shape::setRefPoint(point p)
{
	RefPoint = p;
}
int shape::getfillcolor()
{
	// takes a value from the random generator function
	int c;
	switch (color(c)) {
	case RED:
		return 0;
	case DARKGREEN:
		return 1;
	case  MEDIUMPURPLE:
		return 2;
	case CORNFLOWERBLUE:
		return 3;
	case ORANGE:
		return 4;
	}

	return 0;
}

int shape::findAngle()const
{
	if (RotateTimes % 4 == 0) { return 360; }
	else if ((RotateTimes % 4 != 0) && (RotateTimes % 2 == 0)) { return 180; }
	else if (RotateTimes % 4 != 0) { return 270; }
	else if ((RotateTimes - 1) % 4 == 0) { return 90; }
}
int shape::getShtype() const
{
	return shtype;
}
void shape::setShtype(int s)
{
	shtype = s;
}

void shape::save(ofstream& outfile)
{

	outfile << RefPoint.x << " " << RefPoint.y;
	outfile << RotateTimes << " ";
	outfile << ResizeUpTimes << " ";
	outfile << ResizeDownTimes << " ";
	int fill = getfillcolor();

	outfile << fill << " " << endl;
}

void shape::load(ifstream& Infile)
{
	Infile.open("game.txt");
	if (Infile.is_open()) {
		int rot = 0, up = 0, down = 0, fill = 0;
		Infile >> rot >> up >> down >> fill;
		ResizeUpTimes = up;
		ResizeDownTimes = down;
		RotateTimes = rot;
		fillColor = fill;

		int a = findAngle();
		rotate(a);
		for (int i = 0; i < (ResizeDownTimes); i++) { ResizeDown(); }
		for (int i = 0; i < (ResizeUpTimes); i++) { ResizeUp(); }
		//if (isFlipped) { VerticalFlip();}

	}
}
void shape::setResizeUpTimes() {
	ResizeUpTimes++;
}

void shape::setResizedownTimes() {
	ResizeDownTimes++;
}
int shape:: getup()const {
	return ResizeUpTimes;
}
int shape::getdown()const {
	return ResizeDownTimes;
}
int shape::getx()const {
	return RefPoint.x;
}
int shape::gety()const {
	return RefPoint.y;
}

void shape::Setcolor() {
	fillColor = RED;/*Wait to change fill color*/
}
point shape::getRefPoint()const {
	return RefPoint;
}
double shape::getSize()const {
	return size;
}
