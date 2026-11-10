#include<iostream>

class SubtractionFixture : public testing::Test
{
protected:

    Calculator calc;

    int lhs;
    int rhs;

    void SetUp() override
    {
        std::cout<<"Inside SubtractionFixture::SetUp"<<std::endl;
        lhs = 20;
        rhs = 10;
    }

    void TearDown() override
    {
        std::cout<<"Inside SubtractionFixture::TearDown"<<std::endl;
    }
};