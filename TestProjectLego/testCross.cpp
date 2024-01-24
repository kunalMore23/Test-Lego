#include "pch.h"
#include "Cross.h"

TEST(CrossTest, GetCrossReturnsNonNull)
{
    Cross* cross = Cross::getCross();
    EXPECT_NE(cross, nullptr);
}

TEST(CrossTest, SetSideUpdatesSide)
{
    Cross* cross = Cross::getCross();
    cross->setSide(5.0f);
    EXPECT_FLOAT_EQ(cross->side(), 5.0f);
}

TEST(CrossTest, MakeCrossGeneratesValidCross)
{
    Cross* cross = Cross::getCross();
    cross->setSide(5.0f);
    EXPECT_TRUE(cross->isValid());
}