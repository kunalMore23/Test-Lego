#include "pch.h"
#include "Triangle.h"
using namespace GeometricEntity;

Triangle::Triangle()
    : mP1(0, 0, 0), 
      mP2(0, 0, 0), 
      mP3(0, 0, 0)
{
}

Triangle::Triangle(Point3D p1, Point3D p2, Point3D p3) :mP1(0, 0, 0), mP2(0, 0, 0), mP3(0, 0, 0)
{
    mP1 = p1;
    mP2 = p2;
    mP3 = p3;
}

Triangle::~Triangle()
{
}

Point3D& Triangle::p1()
{
    return mP1;
}

Point3D& Triangle::p2()
{
    return mP2;
}

Point3D& Triangle::p3()
{
    return mP3;
}

Point3D Triangle::normal() const
{
    return mNormal;
}

void Triangle::setNormal(Point3D inNormal)
{
    mNormal = inNormal;
}

bool Triangle::operator==(const Triangle& other) const {
    // Compare all member variables for equality
    return mP1 == other.mP1 &&
        mP2 == other.mP2 &&
        mP3 == other.mP3 &&
        mNormal == other.mNormal;
}