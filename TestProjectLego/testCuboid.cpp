#include "pch.h"
#include "Cuboid.h"

TEST(CuboidTest, ConstructorSetsDimensions)
{
    Cuboid* cuboid = Cuboid::getCuboid(2.0f, 3.0f, 4.0f);
    EXPECT_FLOAT_EQ(cuboid->length(), 2.0f);
    EXPECT_FLOAT_EQ(cuboid->breadth(), 3.0f);
    EXPECT_FLOAT_EQ(cuboid->height(), 4.0f);
}

TEST(CuboidTest, SettersUpdateDimensions)
{
    Cuboid* cuboid = Cuboid::getCuboid(2.0f, 3.0f, 4.0f);
    cuboid->setLength(5.0f);
    cuboid->setBreadth(6.0f);
    cuboid->setHeight(7.0f);

    EXPECT_FLOAT_EQ(cuboid->length(), 5.0f);
    EXPECT_FLOAT_EQ(cuboid->breadth(), 6.0f);
    EXPECT_FLOAT_EQ(cuboid->height(), 7.0f);
}

TEST(CuboidTest, MakeCuboidGeneratesValidCuboid)
{
    Cuboid* cuboid = Cuboid::getCuboid(2.0f, 3.0f, 4.0f);
    EXPECT_TRUE(cuboid->isValid());
}