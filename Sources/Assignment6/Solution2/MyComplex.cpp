/////////////////////////
///// MyComplex.cpp /////
/////////////////////////

#include "MyComplex.h"

myComplex::myComplex(int real, int imag) noexcept
{
    this->real = real;
    this->imag = imag;
}

myComplex::myComplex(const myComplex& other)
{
    if (this == &other)
        return;

    this->real = other.real;
    this->imag = other.imag;
}

myComplex operator+(const myComplex& first, const myComplex& second)
{
    auto real = first.real + second.real;
    auto imag = first.imag + second.imag;

    return myComplex(real, imag);
}

myComplex operator-(const myComplex& first, const myComplex& second)
{
    auto real = first.real - second.real;
    auto imag = first.imag - second.imag;

    return myComplex(real, imag);
}

myComplex operator*(const myComplex& first, const myComplex& second)
{
    auto real = (first.real * second.real) - (first.imag * second.imag);
    auto imag = (first.real * second.imag) + (first.imag * second.real);

    return myComplex(real, imag);
}

myComplex operator+(int first, const myComplex& second)
{
    return myComplex(first) + myComplex(second);
}

myComplex operator-(int first, const myComplex& second)
{
    return myComplex(first) - myComplex(second);
}

myComplex operator*(int first, const myComplex& second)
{
    return myComplex(first) * myComplex(second);
}

myComplex operator+(const myComplex& first, int second)
{
    return myComplex(first) + myComplex(second);
}

myComplex operator-(const myComplex& first, int second)
{
    return myComplex(first) - myComplex(second);
}

myComplex operator*(const myComplex& first, int second)
{
    return myComplex(first) * myComplex(second);
}

myComplex& myComplex::operator=(const myComplex& other)
{
    if (this == &other)
        return *this;

    this->real = other.real;
    this->imag = other.imag;

    return *this;
}

myComplex& myComplex::operator+=(const myComplex& other)
{
    *this = *this + other;
    return *this;
}

myComplex& myComplex::operator-=(const myComplex& other)
{
    *this = *this - other;
    return *this;
}

myComplex& myComplex::operator*=(const myComplex& other)
{
    *this = *this * other;
    return *this;
}

myComplex& myComplex::operator=(int other)
{
    this->real = other;
    this->imag = 0;

    return *this;
}

myComplex& myComplex::operator+=(int other)
{
    *this = *this + other;
    return *this;
}

myComplex& myComplex::operator-=(int other)
{
    *this = *this - other;
    return *this;
}

myComplex& myComplex::operator*=(int other)
{
    *this = *this * other;
    return *this;
}

int myComplex::norm() const
{
    return (this->real * this->real) + (this->imag * this->imag);
}

bool myComplex::operator==(const myComplex& other) const
{
    return (this->real == other.real) and (this->imag == other.imag);
}

bool myComplex::operator!=(const myComplex& other) const
{
    return !(*this == other);
}

bool myComplex::operator>(const myComplex& other) const
{
    return this->norm() > other.norm();
}

bool myComplex::operator>=(const myComplex& other) const
{
    return this->norm() >= other.norm();
}

bool myComplex::operator<(const myComplex& other) const
{
    return this->norm() < other.norm();
}

bool myComplex::operator<=(const myComplex& other) const
{
    return this->norm() <= other.norm();
}

myComplex myComplex::operator-() const
{
    return myComplex(0 - this->real, 0 - this->imag);
}

myComplex myComplex::operator~() const
{
    return myComplex(this->real, 0 - this->imag);
}

myComplex& myComplex::operator++()
{
    this->real++;
    return *this;
}

myComplex& myComplex::operator--()
{
    this->real--;
    return *this;
}

myComplex myComplex::operator++(int)
{
    myComplex obj = *this;
    this->operator++();
    return obj;
}

myComplex myComplex::operator--(int)
{
    myComplex obj = *this;
    this->operator--();
    return obj;
}

std::ostream& operator<<(std::ostream& os, const myComplex& obj)
{
    return os << "(" << obj.real << "," << obj.imag << ")";
}

std::istream& operator>>(std::istream& is, myComplex& obj)
{
    return is >> obj.real >> obj.imag;
}

void myComplex::set(int real, int imag)
{
    this->real = real;
    this->imag = imag;
}

void myComplex::setRealPart(int real)
{
    this->real = real;
}

void myComplex::setImaginaryPart(int imag)
{
    this->imag = imag;
}

int myComplex::getRealPart() const
{
    return this->real;
}

int myComplex::getImaginaryPart() const
{
    return this->imag;
}
