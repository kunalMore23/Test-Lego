#include "pch.h"
#include "Point3D.h"

TEST(testPoint3D, DefaultConstructor) {
    GeometricEntity::Point3D point;
    EXPECT_FLOAT_EQ(point.x(), 0.0f);
    EXPECT_FLOAT_EQ(point.y(), 0.0f);
}

TEST(testPoint3D, ParameterizedConstructor) {
    GeometricEntity::Point3D point(1.0f, 2.0f, 1.0f);
    EXPECT_FLOAT_EQ(point.x(), 1.0f);
    EXPECT_FLOAT_EQ(point.y(), 2.0f);
    EXPECT_FLOAT_EQ(point.z(), 1.0f);
}

TEST(testPoint3D, SettersAndGetters) {
    GeometricEntity::Point3D point;
    point.setX(3.0f);
    point.setY(4.0f);
    point.setZ(4.0f);

    EXPECT_FLOAT_EQ(point.x(), 3.0f);
    EXPECT_FLOAT_EQ(point.y(), 4.0f);
    EXPECT_FLOAT_EQ(point.z(), 4.0f);
}