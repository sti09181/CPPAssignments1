//////////////////////
///// MyTerm.cpp /////
//////////////////////

#include "MyTerm.h"

myTerm::myTerm(int coeff, unsigned int exp) noexcept
{
    this->mCoeff = coeff;
    this->mExp = exp;
}

myTerm::myTerm(const myTerm& other)
{
    if (this == &other)
        return;

    this->mCoeff = other.mCoeff;
    this->mExp = other.mExp;
}

int myTerm::getCoeff() const
{
    return this->mCoeff;
}

unsigned int myTerm::getExp() const
{
    return this->mExp;
}

void myTerm::setCoeff(int coeff)
{
    this->mCoeff = coeff;
}

void myTerm::setExp(unsigned int exp)
{
    this->mExp = exp;
}

myTerm myTerm::ddx() const
{
    if (this->mExp == 0)
        return myTerm(0, 0);

    return myTerm(static_cast<int>(this->mExp) * this->mCoeff, this->mExp - 1);
}

bool myTerm::operator<(const myTerm& other) const
{
    return this->mExp > other.mExp;
}

bool myTerm::operator==(const myTerm& other) const
{
    return (this->mCoeff == other.mCoeff and this->mExp == other.mExp);
}

bool myTerm::operator!=(const myTerm& other) const
{
    return !(*this == other);
}

myTerm myTerm::operator-() const
{
    return myTerm(-this->mCoeff, this->mExp);
}

std::ostream& operator<<(std::ostream& os, const myTerm& obj)
{
    if (obj.mExp == 0)
    {
        if (obj.mCoeff == 0)
            return os;
        else
            return os << obj.mCoeff;
    }

    if (obj.mCoeff == 1)
        os << "x";
    else if (obj.mCoeff == -1)
        os << "-x";
    else
        os << obj.mCoeff << "x";

    if (obj.mExp == 1)
        return os;
    else
        return os << "^" << obj.mExp;
}

myTerm& myTerm::operator=(const myTerm& other)
{
    if (this == &other)
        return *this;

    this->mCoeff = other.mCoeff;
    this->mExp = other.mExp;

    return *this;
}