#include "pch.h"
#include "Cylinder.h"

TEST(CylinderTest, ConstructorSetsSide)
{
    Cylinder* cylinder = Cylinder::getCylinder();
    EXPECT_FLOAT_EQ(cylinder->side(), 0.0f); // Assuming default constructor sets side to 0.0f
}

TEST(CylinderTest, SetSideUpdatesSide)
{
    Cylinder* cylinder = Cylinder::getCylinder();
    cylinder->setSide(5.0f);
    EXPECT_FLOAT_EQ(cylinder->side(), 5.0f);
}

TEST(CylinderTest, MakeCylinderGeneratesValidCylinder)
{
    Cylinder* cylinder = Cylinder::getCylinder();
    cylinder->setSide(5.0f);
    EXPECT_TRUE(cylinder->isValid());
}