#include <gtest/gtest.h>
#include <iostream>
#include "Header/Calculator.h"
#include"Header/TestFixture.h"

TEST_F(TestFixture, AssertPass)
{
    std::cout<<"expectedValue = "<<expectedValue<<std::endl;
    ASSERT_EQ(expectedValue, calc.Add(10,20));
    std::cout<<"After PASS ASSERT"<<std::endl;
}

TEST_F(TestFixture, AssertFail)
{
    std::cout<<"expectedValue = "<<expectedValue<<std::endl;
    expectedValue = 50;
    std::cout<<"expectedValue = "<<expectedValue<<std::endl;
    ASSERT_EQ(expectedValue, calc.Add(10,20));
    std::cout<<"After FAIL ASSERT"<<std::endl;
}

TEST_F(TestFixture, ExpectFail)
{
    expectedValue = 50;
    EXPECT_EQ(expectedValue, calc.Add(10,20));
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

TEST(BooleanTest, CheckTrueEXPECT)
{
    EXPECT_TRUE(10 > 5);
}

TEST(BooleanTest, CheckFalseEXPECT)
{
    EXPECT_FALSE(10 < 5);
}


TEST_F(TestFixture, PositiveNumbers)
{
    ASSERT_EQ(expectedValue, calc.Add(10,20));
}

TEST_F(TestFixture, NegativeNumbers)
{
    expectedValue = -30;
    ASSERT_EQ(expectedValue, calc.Add(-10,-20));
}

TEST_F(TestFixture, WrongResult)
{
    expectedValue = 50;
    ASSERT_EQ(expectedValue, calc.Add(10,20));
    std::cout<<"After FAIL ASSERT"<<std::endl;
}

TEST_F(TestFixture, AddPositiveNumbers)
{
    expectedValue = 10;
    ASSERT_EQ(expectedValue, calc.Sub(20,10));
}

TEST_F(TestFixture, SubNegativeNumbers)
{
    expectedValue = 10;
    ASSERT_EQ(expectedValue, calc.Sub(-20,-10));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}