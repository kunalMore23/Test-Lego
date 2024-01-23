#pragma once
#include "Point3D.h"
#include "pch.h"

namespace GeometricEntity {
    class GEOMETRY_API Triangle
    {
    public:
        Triangle(Point3D p1, Point3D p2, Point3D p3);
        ~Triangle();

        GeometricEntity::Point3D& p1() ;
        GeometricEntity::Point3D& p2() ;
        GeometricEntity::Point3D& p3() ;

        void setNormal(Point3D inNormal);

    private:
        GeometricEntity::Point3D mP1;
        GeometricEntity::Point3D mP2;
        GeometricEntity::Point3D mP3;
        GeometricEntity::Point3D mNormal;
    };
}