#include "pch.h"
#include "Quarto.h"

TEST(QuartoTest, ConstructorSetsSide)
{
    Quarto* quarto = Quarto::getQuarto();
    EXPECT_FLOAT_EQ(quarto->side(), 0.0f); // Assuming default constructor sets side to 0.0f
}

TEST(QuartoTest, SetSideUpdatesSide)
{
    Quarto* quarto = Quarto::getQuarto();
    quarto->setSide(5.0f);
    EXPECT_FLOAT_EQ(quarto->side(), 5.0f);
}

TEST(QuartoTest, MakeQuartoGeneratesValidQuarto)
{
    Quarto* quarto = Quarto::getQuarto();
    quarto->setSide(5.0f);
    EXPECT_TRUE(quarto->isValid());
}