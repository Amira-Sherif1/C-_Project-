#pragma once
#include "CompositeShapes.h"

class game;

class grid
{
	enum { MaxShapeCount = 1000  };	//assuming max shape count = 1000
	
	int rows, cols;	//numner of rows and columns in the grid to draw grid points
	int height, width;
	point uprLeft;	//upper left point of the grid

	//ShapeList should hold the RANDOMLY generated shapes
	shape* shapeList[MaxShapeCount];	//2D array of shape pointers
	int flip[MaxShapeCount];
	int rotation[MaxShapeCount];

	shape* activeShape;	//The shape that the user works on to match to the ranom shapes

	int shapeCount;		//current number of shapes in the list
	int matchedShape = 0 ;   //the number of matched shapes
	
	game* pGame;
	enum shapes { sign, tree, butter, home, cat, Car };
	enum resize { up, down };
public:
	grid(point r_uprleft, int r_width, int r_height, game* r_pGame);
	~grid();
	void draw() const;
	void clearGridArea() const;
	bool addShape(shape* newShape);
	void setActiveShape(shape* actShape);
	void deleteShape();
	shape* getactiveshap()const;
	void Random_Shapes_Generator();
	void randomshape(point refrance,shape* ranshape , int size,int rortat, int fli);
	color getcolor(int x)const;
	void delete_shapelist();
	bool overlap();
	/*void Check_Matching();*/
	int getShType()const;
	void Load();
	void Save();
	void checkoverlaping();
	void delete_shapelist()const;
	void delete_item_shapelist(int i);
	void Check_Matching();
	shape* GetHintShape();
	void Save();
};

