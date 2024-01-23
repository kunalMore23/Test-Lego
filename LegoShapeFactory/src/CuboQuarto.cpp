#include "pch.h"
#include "CuboQuarto.h"
#include "Reader.h"

CuboQuarto::CuboQuarto()
{
	makeCuboQuarto();
}
CuboQuarto::~CuboQuarto()
{

}
CuboQuarto* CuboQuarto::getCuboQuarto()
{
	CuboQuarto* cuboQuarto = new CuboQuarto();
	return cuboQuarto;
}

void CuboQuarto::setSide(float inSide)
{
	mSide = inSide;
}

void CuboQuarto::makeCuboQuarto()
{
	setShapeType("CuboQuarto");
	Reader* reader = new Reader();
	reader->read("K:\\Evaluation_Projects\\Lego-Final\\quarto_cuboidal.stl", triangles);
}