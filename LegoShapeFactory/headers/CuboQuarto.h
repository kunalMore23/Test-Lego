#pragma once
#include <vector>
#include "pch.h"
#include "Triangle.h"
#include "LegoShapeFactory.h"

using namespace GeometricEntity;

class LEGOSHAPEFACTORY_API CuboQuarto : public LegoShapeFactory
{
public:
	static CuboQuarto* getCuboQuarto();
	void setSide(float inSide);

private:
	CuboQuarto();
	~CuboQuarto();
	void makeCuboQuarto();

private:
	float mSide;
};