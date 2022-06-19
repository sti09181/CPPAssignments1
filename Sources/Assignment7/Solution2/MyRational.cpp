//////////////////////////
///// MyRational.cpp /////
//////////////////////////

#include "MyRational.h"

void myRational::reduce()
{
    if (this->data.num == 0 || this->data.den == 0)
    {
        this->data.num = 0;
        this->data.den = 1;
        return;
    }

    if (this->data.den < 0)
    {
        this->data.den *= -1;
        this->data.num *= -1;
    }

    if (this->data.num == 1)
        return;

    int sgn = (this->data.num < 0 ? -1 : 1);
    int g = std::gcd(sgn * this->data.num, this->data.den);
    this->data.num /= g;
    this->data.den /= g;
}

std::tuple<myRational::Data, myRational::Data> myRational::toCommonDenominator(const myRational::Data& firstData, const myRational::Data& secondData)
{
    if (firstData.den == secondData.den)
        return { firstData, secondData };

    auto newFirstData = myRational::Data{ firstData.num * secondData.den, firstData.den * secondData.den };
    auto newSecondData = myRational::Data{ secondData.num * firstData.den, secondData.den * firstData.den };

    return { newFirstData, newSecondData };
}

myRational::myRational(int num, int den) noexcept
{
    this->data.num = num;
    this->data.den = den;

    this->reduce();
}

myRational::myRational(const myRational& other)
{
    if (this == &other)
        return;

    this->data.num = other.data.num;
    this->data.den = other.data.den;

    this->reduce();
}

int myRational::getNumerator() const
{
    return this->data.num;
}

int myRational::getDenominator() const
{
    return this->data.den;
}

myRational myRational::reciprocal() const
{
    return myRational(this->data.den, this->data.num);
}

myRational operator+(const myRational& first, const myRational& second)
{
    auto [newFirstData, newSecondData] = myRational::toCommonDenominator(first.data, second.data);

    auto newNum = newFirstData.num + newSecondData.num;
    auto newDen = newFirstData.den;

    return myRational(newNum, newDen);
}

myRational operator-(const myRational& first, const myRational& second)
{
    auto [newFirstData, newSecondData] = myRational::toCommonDenominator(first.data, second.data);

    auto newNum = newFirstData.num - newSecondData.num;
    auto newDen = newFirstData.den;

    return myRational(newNum, newDen);
}

myRational operator*(const myRational& first, const myRational& second)
{
    auto newNum = first.data.num * second.data.num;
    auto newDen = first.data.den * second.data.den;

    return myRational(newNum, newDen);
}

myRational operator/(const myRational& first, const myRational& second)
{
    return first * second.reciprocal();
}

myRational operator+(const myRational& first, int second)
{
    return first + myRational(second);
}

myRational operator-(const myRational& first, int second)
{
    return first - myRational(second);
}

myRational operator*(const myRational& first, int second)
{
    return first * myRational(second);
}

myRational operator/(const myRational& first, int second)
{
    return first / myRational(second);
}

myRational operator+(int first, const myRational& second)
{
    return myRational(first) + second;
}

myRational operator-(int first, const myRational& second)
{
    return myRational(first) - second;
}

myRational operator*(int first, const myRational& second)
{
    return myRational(first) * second;
}

myRational operator/(int first, const myRational& second)
{
    return myRational(first) / second;
}

myRational& myRational::operator++()
{
    this->data.num += this->data.den;
    return *this;
}

myRational myRational::operator++(int)
{
    myRational oldData = *this;
    this->operator++();
    return oldData;
}

myRational& myRational::operator--()
{
    this->data.num -= this->data.den;
    return *this;
}

myRational myRational::operator--(int)
{
    myRational oldData = *this;
    this->operator--();
    return oldData;
}

myRational myRational::operator-() const
{
    return myRational(-this->data.num, this->data.den);
}

bool operator<(const myRational& first, const myRational& second)
{
    auto [newFirstData, newSecondData] = myRational::toCommonDenominator(first.data, second.data);
    return newFirstData.num < newSecondData.num;
}

bool operator<=(const myRational& first, const myRational& second)
{
    auto [newFirstData, newSecondData] = myRational::toCommonDenominator(first.data, second.data);
    return newFirstData.num <= newSecondData.num;
}

bool operator>(const myRational& first, const myRational& second)
{
    auto [newFirstData, newSecondData] = myRational::toCommonDenominator(first.data, second.data);
    return newFirstData.num > newSecondData.num;
}

bool operator>=(const myRational& first, const myRational& second)
{
    auto [newFirstData, newSecondData] = myRational::toCommonDenominator(first.data, second.data);
    return newFirstData.num >= newSecondData.num;
}

bool operator==(const myRational& first, const myRational& second)
{
    auto [newFirstData, newSecondData] = myRational::toCommonDenominator(first.data, second.data);
    return newFirstData.num == newSecondData.num;
}

bool operator!=(const myRational& first, const myRational& second)
{
    auto [newFirstData, newSecondData] = myRational::toCommonDenominator(first.data, second.data);
    return newFirstData.num != newSecondData.num;
}

bool operator<(const myRational& first, int second)
{
    return first < myRational(second, first.data.den);
}

bool operator<=(const myRational& first, int second)
{
    return first <= myRational(second, first.data.den);
}

bool operator>(const myRational& first, int second)
{
    return first > myRational(second, first.data.den);
}

bool operator>=(const myRational& first, int second)
{
    return first >= myRational(second, first.data.den);
}

bool operator==(const myRational& first, int second)
{
    return first == myRational(second, first.data.den);
}

bool operator!=(const myRational& first, int second)
{
    return first != myRational(second, first.data.den);
}

bool operator<(int first, const myRational& second)
{
    return myRational(first, second.data.den) < second;
}

bool operator<=(int first, const myRational& second)
{
    return myRational(first, second.data.den) <= second;
}

bool operator>(int first, const myRational& second)
{
    return myRational(first, second.data.den) > second;
}

bool operator>=(int first, const myRational& second)
{
    return myRational(first, second.data.den) >= second;
}

bool operator==(int first, const myRational& second)
{
    return myRational(first, second.data.den) == second;
}

bool operator!=(int first, const myRational& second)
{
    return myRational(first, second.data.den) != second;
}

myRational& myRational::operator=(const myRational& other)
{
    if (this == &other)
        return *this;

    this->data.num = other.data.num;
    this->data.den = other.data.den;

    this->reduce();

    return *this;
}

myRational& myRational::operator+=(const myRational& other)
{
    *this = *this + other;
    return *this;
}

myRational& myRational::operator-=(const myRational& other)
{
    *this = *this - other;
    return *this;
}

myRational& myRational::operator*=(const myRational& other)
{
    *this = *this * other;
    return *this;
}

myRational& myRational::operator/=(const myRational& other)
{
    *this = *this / other;
    return *this;
}

myRational& myRational::operator=(int other)
{
    return *this = myRational(other);
}

myRational& myRational::operator+=(int other)
{
    *this = *this + other;
    return *this;
}

myRational& myRational::operator-=(int other)
{
    *this = *this - other;
    return *this;
}

myRational& myRational::operator*=(int other)
{
    *this = *this * other;
    return *this;
}

myRational& myRational::operator/=(int other)
{
    *this = *this / other;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const myRational& obj)
{
    if (obj.data.num == 0)
        os << 0;
    else if (obj.data.den == 1)
        os << obj.data.num;
    else
        os << obj.data.num << "/" << obj.data.den;

    return os;
}

std::istream& operator>>(std::istream& is, myRational& obj)
{
    is >> obj.data.num >> obj.data.den;

    if (obj.data.den == 0)
    {
        obj.data.num = 0;
        obj.data.den = 1;
    }

    obj.reduce();

    return is;
}
