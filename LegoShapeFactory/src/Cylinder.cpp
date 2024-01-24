#include "pch.h"
#include "Cylinder.h"
#include "Reader.h"

Cylinder::Cylinder()
{
	makeCylinder();
}
Cylinder::~Cylinder()
{

}
Cylinder* Cylinder::getCylinder()
{
	Cylinder* cylinder = new Cylinder();
	return cylinder;
}

float Cylinder::side()
{
	return mSide;
}

void Cylinder::setSide(float inSide)
{
	mSide = inSide;
}

void Cylinder::makeCylinder()
{
	setShapeType("Cylinder");
	Reader* reader = new Reader();
	reader->read("K:\\Evaluation_Projects\\Lego-Final\\cylinder.stl", triangles);
}