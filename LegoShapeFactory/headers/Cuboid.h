#pragma once
#include <vector>
#include "pch.h"
#include "Triangle.h"
#include "LegoShapeFactory.h"

using namespace GeometricEntity;

class LEGOSHAPEFACTORY_API Cuboid : public LegoShapeFactory
{
public:
	static Cuboid* getCuboid(float length, float breadth, float height);
	void setLength(float inLength);
	void setBreadth(float inBreadth);
	void setHeight(float inHeight);

private:
	Cuboid(float length, float breadth, float height);
	~Cuboid();
	void makeCuboid();

private:
	float mLength;
	float mBreadth;
	float mHeight;
};