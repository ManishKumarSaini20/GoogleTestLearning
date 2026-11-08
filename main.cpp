#include <gtest/gtest.h>
#include <iostream>
#include "Header/Calculator.h"

TEST(AdditionTest, AssertPass)
{
    Calculator calc;
    ASSERT_EQ(30, calc.Add(10,20));
    std::cout<<"After PASS ASSERT"<<std::endl;
}

TEST(AdditionTest, AssertFail)
{
    Calculator calc;
    ASSERT_EQ(50, calc.Add(10,20));
    std::cout<<"After FAIL ASSERT"<<std::endl;
}

TEST(AdditionTest, ExpectFail)
{
    Calculator calc;
    EXPECT_EQ(50, calc.Add(10,20));
    std::cout<<"After FAIL EXPECT"<<std::endl;
}

TEST(BooleanTest, CheckTrue)
{
    ASSERT_TRUE(10 > 5);
}

TEST(BooleanTest, CheckFalse)
{
    ASSERT_FALSE(10 < 5);
}

TEST(AdditionTest, PositiveNumbers)
{
    Calculator calc;
    ASSERT_EQ(30, calc.Add(10,20));
}

TEST(AdditionTest, NegativeNumbers)
{
    Calculator calc;
    ASSERT_EQ(-30, calc.Add(-10,-20));
}

TEST(AdditionTest, WrongResult)
{
    Calculator calc;
    ASSERT_EQ(50, calc.Add(10,20));
    std::cout<<"After FAIL ASSERT"<<std::endl;
}

TEST(SubstractionTest, PositiveNumbers)
{
    Calculator calc;
    ASSERT_EQ(10, calc.Sub(20,10));
}

TEST(SubstractionTest, NegativeNumbers)
{
    Calculator calc;
    ASSERT_EQ(10, calc.Sub(-20,-10));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}