#include "pch.h"
#include "Cube.h"
#include "Reader.h"

Cube::

Cube::Cube(float side)
{
	makeCube(side);
}
Cube::~Cube()
{

}
Cube* Cube::getCube(float side)
{
	Cube* cube = new Cube(side);
	return cube;
}

void Cube::setSide(float inSide)
{
	mSideLength = inSide;
}

void Cube::makeCube(float side)
{
	setShapeType("Cube");
	Reader* reader = new Reader();
	reader->read("K:\\Evaluation_Projects\\Lego-Final\\cube.stl", triangles, side);
	mSideLength = side;
}

float Cube::getSideLength()
{
	return mSideLength;
}
