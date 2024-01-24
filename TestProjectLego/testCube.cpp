#include "pch.h"
#include "Cube.h"

TEST(CubeTest, GetCrossReturnsNonNull)
{
    Cube* cube = Cube::getCube(4.0);
    EXPECT_NE(cube, nullptr);
}

TEST(CubeTest, SetSideUpdatesSide)
{
    Cube* cube = Cube::getCube(4.0);
    cube->setSide(5.0f);
    EXPECT_FLOAT_EQ(cube->side(), 5.0f);
}

TEST(CubeTest, MakeCubeGeneratesValidCube)
{
    Cube* cube = Cube::getCube(4.0);
    cube->setSide(5.0f);
    EXPECT_TRUE(cube->isValid());
}