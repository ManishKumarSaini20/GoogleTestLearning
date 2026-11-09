#include<iostream>

class TestFixture : public testing::Test
{
    protected:
    Calculator calc;
    int expectedValue;
    public:
    void SetUp() override
    {
        std::cout<<"Inside SetUp"<<std::endl;
        expectedValue = 30;
    }

    void TearDown() override
    {
        std::cout<<"Inside TearDown"<<std::endl;
    }
};