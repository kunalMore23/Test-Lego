#pragma once
#include "pch.h"
#include "Triangle.h"
#include "LegoShapeFactory.h"

using namespace GeometricEntity;

class LEGOSHAPEFACTORY_API Quarto : public LegoShapeFactory
{
public:
	static Quarto* getQuarto();
	void setSide(float inSide);

private:
	Quarto();
	~Quarto();
	void makeQuarto();

private:
	float mSide;
};