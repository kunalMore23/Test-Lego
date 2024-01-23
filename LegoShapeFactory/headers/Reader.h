#pragma once

#include "pch.h"
#include "Triangle.h"

#include <string>
#include <vector>

using Triangle = GeometricEntity::Triangle;
using Point3D = GeometricEntity::Point3D;

class LEGOSHAPEFACTORY_API Reader
{
public:
	Reader();
	~Reader();

	void read(std::string inFilePath, std::vector<Triangle>& inTriangles, float side);
	void read(std::string inFilePath, std::vector<Triangle>& inTriangles);
};
