#include<iostream>

class TestFixture : public testing::Test
{
protected:

    Calculator calc;

    int expectedValue;

    int inputA;

    int inputB;

    void SetUp() override
    {
        expectedValue = 30;

        inputA = 10;
        inputB = 20;

        std::cout<<"Inside TestFixture::SetUp"<<std::endl;
    }

    void TearDown() override
    {
        std::cout<<"Inside TestFixture::TearDown"<<std::endl;
    }
};