#include "pch.h"
#include "Cuboid.h"
#include "Reader.h"

Cuboid::Cuboid(float length, float breadth, float height) : mLength(length), mBreadth(breadth), mHeight(height)
{
	makeCuboid();
}

Cuboid::~Cuboid()
{

}

Cuboid* Cuboid::getCuboid(float length, float breadth, float height)
{
	Cuboid* cuboid = new Cuboid(length, breadth, height);
	return cuboid;
}

void Cuboid::setLength(float inLength)
{
	mLength = inLength;
}

void Cuboid::setBreadth(float inBreadth)
{
	mBreadth = inBreadth;
}

void Cuboid::setHeight(float inHeight)
{
	mHeight = inHeight;
}

void Cuboid::makeCuboid()
{
	setShapeType("Cuboid");
	Reader* reader = new Reader();
	reader->read("K:\\Evaluation_Projects\\Lego-Final\\cuboid.stl", triangles);
}