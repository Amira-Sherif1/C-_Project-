#pragma once
#include <string>
using namespace std;
#include "CMUgraphicsLib\CMUgraphics.h"

class game;     //forward declaration

struct point
{
	int x, y;
};

/*enum ShapeType
{
	//Basic shapes
	RCT,	//rectangle
	CRC,	//circle
	TRI,	//triangle

	//Composite shapes
	SIGN,	//a street sign
	
	//TODO: Add more types
};*/

//Base class for all shapes including Basic shapes, Composite shapes
class shape
{
protected:
	point RefPoint;		//Each shape must have a reference point
    game* pGame;        //pointer to game object
	color fillColor;	//shape fill color
	color borderColor;	//shape border color
	double size = 1;	//the size of the shape and it will be used in resize up and resize down function
	int stepsCounter = 0;	//how many step the shape move
public:
    shape(game* r_pGame, point ref);
	void setRefPoint(point p);
	point getRefPoint() const;
    virtual void draw() const=0;//for a shape to draw itself on the screen
	virtual void ResizeUp()=0;
	virtual void ResizeDown() = 0;
	virtual void move(char step) = 0 ;		//Move the shape
	void rotate(int angle, point ref);
	//virtual ~shape();

	double getSize() const;
	//virtual string MyType() = 0;		// to know the type of the shape "the divered shape" 

	//-- The following functions should be supported by the shape class
	//-- It should be overridden by each inherited shape
	//-- Decide the parameters that you should pass to each function	

//virtual void rotate() = 0;	//Rotate the shape
	//virtual void resize() = 0;	//Resize the shape
	
	//virtual void save(ofstream &OutFile) = 0;	//Save the shape parameters to the file
	//virtual void load(ifstream &Infile) = 0;	//Load the shape parameters to the file

};




