#pragma once
#ifndef POINT2D_H
#define POINT2D_H
#include "pch.h"

namespace GeometricEntity {

    class GEOMETRY_API Point2D
    {
    public:
        Point2D();
        Point2D(float inX, float inY);
        ~Point2D();

        float x() const;
        float y() const;

        void setX(float x);
        void setY(float y);

    private:
        float mX;
        float mY;
    };
}
#endif POINT2D_H

