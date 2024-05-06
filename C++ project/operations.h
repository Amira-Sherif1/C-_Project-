#pragma once

class game;
/////////////////////////////////// class operation  //////////////////
//Base class of all operations supported by the application
class operation
{
protected:
	game* pGame;	//pointer to the game class
public:
	operation(game* r_pGame);

	//Function Act:
	//Implements the action that should be taken by this operation
	//Should be overriden by derived classes
	virtual void Act() = 0;
};
/////////////////////////////////// class operAddSign  //////////////////
//Responsible for 
//1- collectign data about a new Sign shape to add
//2- Adding the new shape to the list of shapes (throgh the grid class)
class operAddSign:public operation
{
public:
	operAddSign(game* r_pGame);
	virtual void Act();
};

class operAddTree : public operation
{
public:
	operAddTree(game* r_pGame);
	virtual void Act();
};

class operAddBoat : public operation
{
public:
	operAddBoat(game* r_pGame);
	virtual void Act();
};

class operAddButterfly :public operation
{
public:
	operAddButterfly(game* r_pgame);
	virtual void Act();
};
/*class operAddCone :public operation
{
public:
	operAddCone(game* r_pGame);
	virtual void Act();
};*/


class operAddHome :public operation
{
public:
	operAddHome(game* r_pGame);
	virtual void Act();
};


class operAddCat :public operation
{
public:
	operAddCat(game* r_pGame);
	virtual void Act();
};

class operAddcar :public operation
{
public:
	operAddcar(game* r_pGame);
	virtual void Act();
};

class operResizeUp :public operation {
public:
	operResizeUp(game* r_pGame);
	virtual void Act();

};

class operResizeDown :public operation {
public:
	operResizeDown(game* r_pGame);
	virtual void Act();
};


class operDelete :public operation
{
public:
	operDelete(game* r_pGame);
	virtual void Act();
};


