#include "pch.h"
#include "Point2D.h"

TEST(Point2DTest, DefaultConstructor) {
    GeometricEntity::Point2D point;
    EXPECT_FLOAT_EQ(point.x(), 0.0f);
    EXPECT_FLOAT_EQ(point.y(), 0.0f);
}

TEST(Point2DTest, ParameterizedConstructor) {
    GeometricEntity::Point2D point(1.0f, 2.0f);
    EXPECT_FLOAT_EQ(point.x(), 1.0f);
    EXPECT_FLOAT_EQ(point.y(), 2.0f);
}

TEST(Point2DTest, SettersAndGetters) {
    GeometricEntity::Point2D point;
    point.setX(3.0f);
    point.setY(4.0f);

    EXPECT_FLOAT_EQ(point.x(), 3.0f);
    EXPECT_FLOAT_EQ(point.y(), 4.0f);
}