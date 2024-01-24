#include "pch.h"
#include "CuboQuarto.h"

TEST(CuboQuartoTest, ConstructorSetsSide)
{
    CuboQuarto* cuboQuarto = CuboQuarto::getCuboQuarto();
    EXPECT_FLOAT_EQ(cuboQuarto->side(), 0.0f); // Assuming default constructor sets side to 0.0f
}

TEST(CuboQuartoTest, SetSideUpdatesSide)
{
    CuboQuarto* cuboQuarto = CuboQuarto::getCuboQuarto();
    cuboQuarto->setSide(5.0f);
    EXPECT_FLOAT_EQ(cuboQuarto->side(), 5.0f);
}

TEST(CuboQuartoTest, MakeCuboQuartoGeneratesValidCuboQuarto)
{
    CuboQuarto* cuboQuarto = CuboQuarto::getCuboQuarto();
    cuboQuarto->setSide(5.0f);
    EXPECT_TRUE(cuboQuarto->isValid());
}