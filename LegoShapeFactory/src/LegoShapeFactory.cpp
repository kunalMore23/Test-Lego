#include "pch.h"
#include "framework.h"
#include "LegoShapeFactory.h"

// This is the constructor of a class that has been exported.
LegoShapeFactory::LegoShapeFactory() : mShapeType("Not assigned"), mShapeColor(GeometricEntity::Point3D(1.0f, 1.0f, 0.0f))
{
}

std::vector<GeometricEntity::Triangle>& LegoShapeFactory::getTriangles() 
{
    return triangles;
}

int LegoShapeFactory::getIndex() const
{
    return mShapeIndex;
}

GeometricEntity::Point3D LegoShapeFactory::color() const
{
    return mShapeColor;
}

std::string LegoShapeFactory::shapeType() const
{
    return mShapeType;
}

void LegoShapeFactory::setColor(GeometricEntity::Point3D inColor)
{
    mShapeColor = inColor;
}

void LegoShapeFactory::setIndex(int inIndex)
{
    mShapeIndex = inIndex++;
}


void LegoShapeFactory::setShapeType(std::string shapeType)
{
    mShapeType = shapeType;
}


void LegoShapeFactory::setTriangles(std::vector<GeometricEntity::Triangle> inTriangles)
{
    triangles = inTriangles;
}

void LegoShapeFactory::rotate(GeometricEntity::Point3D rotationVector)
{
    for (size_t i = 0; i < triangles.size(); i++)
    {
        rotatePoint(triangles[i].p1(), rotationVector.x(), 'x');
        rotatePoint(triangles[i].p1(), rotationVector.y(), 'y');
        rotatePoint(triangles[i].p1(), rotationVector.z(), 'z');

        rotatePoint(triangles[i].p2(), rotationVector.x(), 'x');
        rotatePoint(triangles[i].p2(), rotationVector.y(), 'y');
        rotatePoint(triangles[i].p2(), rotationVector.z(), 'z');
        
        rotatePoint(triangles[i].p3(), rotationVector.x(), 'x');
        rotatePoint(triangles[i].p3(), rotationVector.y(), 'y');
        rotatePoint(triangles[i].p3(), rotationVector.z(), 'z');
    }
}

void LegoShapeFactory::rotatePoint(GeometricEntity::Point3D& p, double degree, char axis)
{
    double angle = degree * 3.14 / 180;
    double xd(0.0), yd(0.0), zd(0.0);
    switch (axis) {
    case 'x': {
        double xp = p.x();
        double yp = p.y();
        double zp = p.z();
        //matrix multiplication / rotation matrix for rotating point around x axis
        xd = xp;
        yd = (yp * cos(angle)) - (zp * sin(angle));
        zd = (yp * sin(angle)) + (zp * cos(angle));
        break;
    }
    case 'y': {
        double xp = p.x();
        double yp = p.y();
        double zp = p.z();

        //matrix multiplication / rotation matrix for rotating point around y axis
        xd = (zp * sin(angle)) + (xp * cos(angle));
        yd = yp;
        zd = (zp * cos(angle)) - (xp * sin(angle));
        break;
    }
    case 'z': {
        double xp = p.x();
        double yp = p.y();
        double zp = p.z();

        //matrix multiplication / rotation matrix for rotating point around x axis
        xd = (xp * cos(angle)) - (yp * sin(angle));
        yd = (xp * sin(angle)) + (yp * cos(angle));
        zd = zp;
    }
    }
    p.setX(xd);
    p.setY(yd);
    p.setZ(zd);
}