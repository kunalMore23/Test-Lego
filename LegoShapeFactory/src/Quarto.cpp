#include "pch.h"
#include "Quarto.h"
#include "Reader.h"

Quarto::Quarto()
{
	makeQuarto();
}

Quarto::~Quarto()
{

}

Quarto* Quarto::getQuarto()
{
	Quarto* quarto = new Quarto();
	return quarto;
}

float Quarto::side()
{
	return mSide;
}

void Quarto::setSide(float inSide)
{
	mSide = inSide;
}

void Quarto::makeQuarto()
{
	setShapeType("Quarto");
	Reader* reader = new Reader();
	reader->read("K:\\Evaluation_Projects\\Lego-Final\\quarto.stl", triangles, mSide);
}