#include <gtest/gtest.h>
#include <iostream>
#include "Header/Calculator.h"
#include "Header/TestFixture.h"
#include "Header/SubtractionFixture.h"
#include "Header/Fixture.h"
#include "Header/EvenNumberTest.h"

TEST_F(TestFixture, NAssertPass)
{
    std::cout<<"expectedValue = "<<expectedValue<<'\n';
    expectedValue = 20;
    std::cout<<"expectedValue = "<<expectedValue<<'\n';
    EXPECT_EQ(expectedValue, calc.Add(5,15));
    std::cout<<"After PASS EXPECT"<<std::endl;
}

TEST_F(Fixture, NAssertStaticFixture)
{
    std::cout<<"testCounter = "<<testCounter<<std::endl;
    testCounter = 30;
    std::cout<<"testCounter = "<<testCounter<<std::endl;
    EXPECT_EQ(testCounter, calc.Add(10,20));
    std::cout<<"After PASS EXPECT.\n";
}

TEST_F(Fixture, NAssertStaticFixture2)
{
    std::cout<<"testCounter = "<<testCounter<<std::endl;
    EXPECT_EQ(testCounter, calc.Add(10,20));
    std::cout<<"After PASS EXPECT.\n";
}

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

TEST_F(TestFixture, SharedInputs)
{
    ASSERT_EQ(expectedValue, calc.Add(inputA,inputB));
}

TEST_F(TestFixture, ModifyInputA)
{
    inputA = 40;
    expectedValue = 60;
    ASSERT_EQ(expectedValue, calc.Add(inputA, inputB));
}

TEST_F(TestFixture, VerifyInputAReset)
{
    ASSERT_EQ(10, inputA);
}

TEST_F(SubtractionFixture, PositiveSubtraction)
{
    ASSERT_EQ(10, calc.Sub(lhs, rhs));
}

TEST_F(TestFixture, VerifyInputBReset)
{
    ASSERT_EQ(20,inputB);
}

TEST_F(TestFixture, VerifyInputAReset1)
{
    ASSERT_EQ(10, inputA);
}

TEST_F(TestFixture, ModifyInputB)
{
    inputB = 50;
    ASSERT_EQ(50, inputB);
}

TEST_F(Fixture, TestTest)
{
    std::cout<<"testCounter = "<<testCounter<<'\n';
    ++testCounter;
    ASSERT_EQ(10, 10);
}

TEST_F(Fixture, TestTest1)
{
    std::cout<<"testCounter = "<<testCounter<<'\n';
    ++testCounter;
    ASSERT_TRUE(1 == 1);
}

TEST_F(Fixture, TestTest2)
{
    std::cout<<"testCounter = "<<testCounter<<'\n';
    ++testCounter;
    ASSERT_TRUE(1 == 1);
}

INSTANTIATE_TEST_SUITE_P(
    EvenValues,          // Instance name
    EvenNumberTest,    // Test fixture
    ::testing::Values(2, 4, 6, 8, 9)
);

TEST_P(EvenNumberTest, CheckEven)
{
    int num = GetParam();

    EXPECT_EQ(num % 2, 0);
}

INSTANTIATE_TEST_SUITE_P(
    OddValues,          // Instance name
    OddNumberTest,    // Test fixture
    ::testing::Values(1, 3, 5, 7, 9)
);

TEST_P(OddNumberTest, CheckOdd)
{
    int num = GetParam();

    EXPECT_EQ(num % 2, 1);
}

INSTANTIATE_TEST_SUITE_P(
    AddValuesCheck, AddNumbers, ::testing::Values(std::make_tuple(1,2,3), std::make_tuple(4,5,9))
);

TEST_P(AddNumbers, CheckAdd)
{
    //auto [a,b,ExpectedValue] = GetParam();
    int a = std::get<0>(GetParam());
    int b = std::get<1>(GetParam());
    int ExpectedValue = std::get<2>(GetParam());
    EXPECT_EQ(ExpectedValue, cal.Add(a,b));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}