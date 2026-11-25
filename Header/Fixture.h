#include <iostream>

class Fixture : public testing::Test
{
protected:
    static int testCounter;
    Calculator calc;
    
    static void SetUpTestSuite()
    {
        std::cout<<"Suite Setup\n";
    }

    static void TearDownTestSuite()
    {
        std::cout<<"Suite TearDown\n";
    }

    // void SetUp() override
    // {
    //     std::cout<<"Inside SetUp.\n";
    // }

    // void TearDown() override
    // {
    //     std::cout<<"Inside TearDown.\n";
    // }
};

int Fixture::testCounter = 0;