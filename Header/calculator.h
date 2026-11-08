#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator
{
    int m_i;
    int m_j;

public:

    explicit Calculator(int i = 0, int j = 0) noexcept;

    ~Calculator() noexcept;

    int Add(int i, int j) noexcept;

    int Sub(int i, int j) noexcept;
};

#endif