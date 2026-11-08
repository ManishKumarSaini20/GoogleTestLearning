#include "../Header/Calculator.h"

Calculator::Calculator(int i, int j) noexcept : m_i(i), m_j(j)
{
}

Calculator::~Calculator() noexcept
{
}

int Calculator::Add(int i, int j) noexcept
{
    return i + j;
}

int Calculator::Sub(int i, int j) noexcept
{
    if(i > j)
    {
        return i-j;
    }
    else
    {
        return j-i;
    }
}