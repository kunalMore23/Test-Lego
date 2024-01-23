#pragma once
#include <vector>
#include "pch.h"
#include "Triangle.h"
#include "LegoShapeFactory.h"

using namespace GeometricEntity;

class LEGOSHAPEFACTORY_API Cylinder : public LegoShapeFactory
{
public:
	static Cylinder* getCylinder();
	void setSide(float inSide);

private:
	Cylinder();
	~Cylinder();
	void makeCylinder();

private:
	float mSide;
};