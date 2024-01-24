#include "pch.h"
#include "Cross.h"
#include "Reader.h"

Cross::Cross()
{
	makeCross();
}
Cross::~Cross()
{

}
Cross* Cross::getCross()
{
	Cross* cross = new Cross();
	return cross;
}

float Cross::side() const
{
	return mSide;
}

void Cross::setSide(float inSide)
{
	mSide = inSide;
}

void Cross::makeCross()
{
	setShapeType("Cross");
	Reader* reader = new Reader();
	reader->read("K:\\Evaluation_Projects\\Lego-Final\\hooked_cross.stl", triangles);
}