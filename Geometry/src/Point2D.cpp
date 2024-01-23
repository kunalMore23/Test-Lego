#include "pch.h"
#include "Point2D.h"
using namespace GeometricEntity;

GeometricEntity::Point2D::Point2D()
    :mX(0),
    mY(0)
{
}

Point2D::Point2D(float inX, float inY)
    :mX(0),
    mY(0)
{
    mX = inX;
    mY = inY;
}

Point2D::~Point2D()
{
}

float Point2D::x() const
{
    return mX;
}

float Point2D::y() const
{
    return mY;
}


void Point2D::setX(float x) {
    mX = x;
}

void Point2D::setY(float y) {
    mY = y;
}
