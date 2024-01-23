#pragma once
#include "pch.h"
#include "Point3D.h"
#include "Triangulation.h"
#include <vector>
#include <string> 

// This class is exported from the dll
class LEGOSHAPEFACTORY_API LegoShapeFactory {
public:
	LegoShapeFactory();

public:
	std::vector<GeometricEntity::Triangle>& getTriangles() ;
	int getIndex() const;
	GeometricEntity::Point3D color() const;
	std::string shapeType() const;

	void setColor(GeometricEntity::Point3D);
	void setIndex(int inIndex);
	void setTriangles(std::vector<GeometricEntity::Triangle> inTriangles);
	void rotate(GeometricEntity::Point3D rotationVector);

protected:
	void setShapeType(std::string shapeType);
	std::vector<GeometricEntity::Triangle> triangles;
	void rotatePoint(GeometricEntity::Point3D& p, double degree, char axis);

private:
	std::string					mShapeType;
	int							mShapeIndex;
	GeometricEntity::Point3D	mShapeColor;
};