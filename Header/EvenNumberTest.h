#include <iostream>
#include <tuple>

class EvenNumberTest : public ::testing::TestWithParam<int>
{
};

class OddNumberTest : public ::testing::TestWithParam<int>
{
};


class AddNumbers:public ::testing::TestWithParam<std::tuple<int,int,int>>
{
    protected:
    Calculator cal;
};

