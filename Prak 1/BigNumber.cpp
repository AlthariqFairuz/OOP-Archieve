#include "BigNumber.hpp"
#include <iostream>
using namespace std;

const int BigNumber::max_digit = 20;

BigNumber::BigNumber()
{
    this->digit = new int[BigNumber::max_digit];
}

BigNumber::BigNumber(int number)
{
    this->digit = new int[BigNumber::max_digit];
    for (int i = 0; i < BigNumber::max_digit; i++)
    {
        this->digit[i] = number % 10;
        number /= 10;
    }
}

BigNumber::BigNumber(string aVeryBigNumber) : digit(new int[BigNumber::max_digit])
{
    for (int i = 0; i < BigNumber::max_digit; i++)
    {
        this->digit[i] = (i < aVeryBigNumber.size()) ? aVeryBigNumber[aVeryBigNumber.size() - 1 - i] - '0' : 0;
    }
}
BigNumber::BigNumber(const BigNumber &bn)
{
    this->digit = new int[BigNumber::max_digit];
    for (int i = 0; i < BigNumber::max_digit; i++)
    {
        this->digit[i] = bn[i];
    }
}

int BigNumber::getMaxDigit()
{
    return BigNumber::max_digit;
}

void BigNumber::setDigit(int i, int digit)
{
    this->digit[i] = digit;
}

int &BigNumber::operator[](int i)
{
    return this->digit[i];
}

int BigNumber::operator[](int i) const
{
    return this->digit[i];
}

BigNumber::~BigNumber()
{
    delete[] this->digit;
}

// hint   : gunakan operator overload [] untuk mengakses digit
// contoh : other[i]
// hint   : untuk this, dapat langsung menggunakan this->digit[i]
bool BigNumber::operator==(const BigNumber &other)
{
    for (int i = BigNumber::getMaxDigit() - 1; i >= 0; i--)
    {
        if (this->digit[i] != other[i])
        {
            return false;
        }
    }
    return true;
}

bool BigNumber::operator<(const BigNumber &other)
{
    for (int i = BigNumber::getMaxDigit() - 1; i >= 0; i--)
    {
        if (this->digit[i] < other[i])
        {
            return true;
        }
    }
    return false;
}

bool BigNumber::operator>(const BigNumber &other)
{
    for (int i = BigNumber::getMaxDigit() - 1; i >= 0; i--)
    {
        if (this->digit[i] > other[i])
        {
            return true;
        }
    }
    return false;
}

BigNumber BigNumber::operator+(const BigNumber &other)
{
    BigNumber c;
    // hint: gunakan operator overload [] untuk mengakses dan mengubah digit
    // contoh:
    // - c[i] = this->digit[i]
    // - c[i] = other[i]
    int lebih = 0;
    for (int i = 0; i < BigNumber::getMaxDigit(); i++)
    {
        int sum = this->digit[i] + other[i] + lebih;
        c[i] = sum % 10;
        lebih = sum / 10;
    }
    return c;
}