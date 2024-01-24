#pragma once
#include "pch.h"
#include "Triangle.h"
#include "LegoShapeFactory.h"
#include <memory>
using namespace GeometricEntity;

class LEGOSHAPEFACTORY_API Cross : public LegoShapeFactory
{
public:
	static Cross* getCross();
	//getters
	float side() const;
	//setters
	void setSide(float inSide);

private:
	Cross();
	~Cross();
	void makeCross();

private:
	float mSide;
};