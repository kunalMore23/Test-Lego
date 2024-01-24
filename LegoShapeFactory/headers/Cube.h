#pragma once
#include <vector>
#include "pch.h"
#include "Point3D.h"
#include "Triangle.h"
#include "LegoShapeFactory.h"

using namespace GeometricEntity;

class LEGOSHAPEFACTORY_API Cube : public LegoShapeFactory
{
public:
	static Cube* getCube(float side);
	//getters
	float side();
	//setters
	void setSide(float inSide);

private:
	Cube(float side);
	~Cube();
	void makeCube(float side);

private:
	float mSideLength;
};