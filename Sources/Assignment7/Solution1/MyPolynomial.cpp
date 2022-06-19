////////////////////////////
///// MyPolynomial.cpp /////
////////////////////////////

#include "MyPolynomial.h"

const myPolynomial myPolynomial::ZERO(0, 0u);
const myPolynomial myPolynomial::ONE(1, 0u);
const myPolynomial myPolynomial::X(1, 1u);

void myPolynomial::sort()
{
    bool isSwapped;

    do
    {
        isSwapped = false;

        for (auto it = std::next(this->listOfTerms.begin(), 1); it != this->listOfTerms.end(); it++)
        {
            if (std::next(it, -1)->getExp() < it->getExp())
            {
                std::swap(*std::next(it, -1), *it);
                isSwapped = true;
            }
        }

    } while (isSwapped);
}

myPolynomial::myPolynomial(int coeff, unsigned int exp) noexcept
{
    this->degree = 0;

    if (coeff != 0)
    {
        this->listOfTerms.emplace_back(coeff, exp);
        this->degree = static_cast<int>(exp);
    }
}

myPolynomial::myPolynomial(int countOfTerms, int arrayOfTerms[]) noexcept
{
    this->degree = 0;

    for (int i = 0, sizeOfArray = 2 * countOfTerms; i < sizeOfArray; i += 2)
    {
        if (arrayOfTerms[i] != 0)
        {
            this->listOfTerms.emplace_back(arrayOfTerms[i], arrayOfTerms[i + 1]);
            this->degree = std::max(this->degree, arrayOfTerms[i + 1]);
        }
    }

    this->sort();
}

myPolynomial::myPolynomial(const myPolynomial& other)
{
    if (this == &other)
        return;

    this->listOfTerms.assign(other.listOfTerms.begin(), other.listOfTerms.end());
    this->degree = other.degree;
}

int myPolynomial::getDegree() const
{
    return this->degree;
}

int myPolynomial::getNumTerms() const
{
    return static_cast<int>(this->listOfTerms.size());
}

myPolynomial myPolynomial::ddx() const
{
    myPolynomial result;

    for (const auto& currentTermOfPolynomial : this->listOfTerms)
    {
        auto newTerm = currentTermOfPolynomial.ddx();

        if (newTerm.getCoeff() != 0)
        {
            result.listOfTerms.emplace_back(newTerm);
            result.degree = std::max(result.degree, static_cast<int>(newTerm.getExp()));
        }
    }

    result.sort();

    return result;
}

myPolynomial operator+(const myPolynomial& first, const myPolynomial& second)
{
    if (first == myPolynomial::ZERO and second == myPolynomial::ZERO)
        return myPolynomial::ZERO;
    else if (first == myPolynomial::ZERO)
        return second;
    else if (second == myPolynomial::ZERO)
        return first;

    myPolynomial result;

    auto currentTermOfFirstPolynomial = first.listOfTerms.begin();
    auto currentTermOfSecondPolynomial = second.listOfTerms.begin();

    while (currentTermOfFirstPolynomial != first.listOfTerms.end() and currentTermOfSecondPolynomial != second.listOfTerms.end())
    {
        if (currentTermOfFirstPolynomial->getExp() > currentTermOfSecondPolynomial->getExp())
        {
            if (currentTermOfFirstPolynomial->getCoeff() != 0)
            {
                result.listOfTerms.emplace_back(currentTermOfFirstPolynomial->getCoeff(), currentTermOfFirstPolynomial->getExp());
                result.degree = std::max(result.degree, static_cast<int>(currentTermOfFirstPolynomial->getExp()));
            }

            currentTermOfFirstPolynomial++;
        }
        else if (currentTermOfFirstPolynomial->getExp() < currentTermOfSecondPolynomial->getExp())
        {
            if (currentTermOfSecondPolynomial->getCoeff() != 0)
            {
                result.listOfTerms.emplace_back(currentTermOfSecondPolynomial->getCoeff(), currentTermOfSecondPolynomial->getExp());
                result.degree = std::max(result.degree, static_cast<int>(currentTermOfSecondPolynomial->getExp()));
            }

            currentTermOfSecondPolynomial++;
        }
        else
        {
            if (currentTermOfFirstPolynomial->getCoeff() + currentTermOfSecondPolynomial->getCoeff() != 0)
            {
                result.listOfTerms.emplace_back(currentTermOfFirstPolynomial->getCoeff() + currentTermOfSecondPolynomial->getCoeff(), currentTermOfFirstPolynomial->getExp());
                result.degree = std::max(result.degree, static_cast<int>(currentTermOfFirstPolynomial->getExp()));
            }

            currentTermOfFirstPolynomial++;
            currentTermOfSecondPolynomial++;
        }
    }

    while (currentTermOfFirstPolynomial != first.listOfTerms.end())
    {
        if (currentTermOfFirstPolynomial->getCoeff() != 0)
        {
            result.listOfTerms.emplace_back(currentTermOfFirstPolynomial->getCoeff(), currentTermOfFirstPolynomial->getExp());
            result.degree = std::max(result.degree, static_cast<int>(currentTermOfFirstPolynomial->getExp()));
        }

        currentTermOfFirstPolynomial++;
    }

    while (currentTermOfSecondPolynomial != second.listOfTerms.end())
    {
        if (currentTermOfSecondPolynomial->getCoeff() != 0)
        {
            result.listOfTerms.emplace_back(currentTermOfSecondPolynomial->getCoeff(), currentTermOfSecondPolynomial->getExp());
            result.degree = std::max(result.degree, static_cast<int>(currentTermOfSecondPolynomial->getExp()));
        }

        currentTermOfSecondPolynomial++;
    }

    result.sort();

    return result;
}

myPolynomial operator-(const myPolynomial& first, const myPolynomial& second)
{
    return first + -second;
}

myPolynomial operator*(const myPolynomial& first, const myPolynomial& second)
{
    if (first == myPolynomial::ZERO or second == myPolynomial::ZERO)
        return myPolynomial::ZERO;
    else if (first == myPolynomial::ONE)
        return second;
    else if (second == myPolynomial::ONE)
        return first;

    std::list<myPolynomial> listOfPolynomial;

    for (const auto& currentTermOfFirstPolynomial : first.listOfTerms)
    {
        myPolynomial polynomial;

        for (const auto& currentTermOfSecondPolynomial : second.listOfTerms)
        {
            auto newCoeff = currentTermOfFirstPolynomial.getCoeff() * currentTermOfSecondPolynomial.getCoeff();
            auto newExp = currentTermOfFirstPolynomial.getExp() + currentTermOfSecondPolynomial.getExp();

            if (newCoeff != 0)
            {
                polynomial.listOfTerms.emplace_back(newCoeff, newExp);
                polynomial.degree = std::max(polynomial.degree, static_cast<int>(newExp));
            }
        }

        polynomial.sort();

        listOfPolynomial.emplace_back(polynomial);
    }

    myPolynomial result;

    auto currentPolynomial = listOfPolynomial.begin();

    while (currentPolynomial != listOfPolynomial.end())
    {
        result += *currentPolynomial;
        currentPolynomial++;
    }

    result.sort();

    return result;
}

myPolynomial operator*(const myPolynomial& first, int second)
{
    return first * myPolynomial(second);
}

myPolynomial operator*(int first, const myPolynomial& second)
{
    return myPolynomial(first) * second;
}

int myPolynomial::operator()(int x) const
{
    int result = 0;

    for (const auto& currentTermOfPolynomial : this->listOfTerms)
        result += currentTermOfPolynomial.getCoeff() * static_cast<int>(std::pow(x, currentTermOfPolynomial.getExp()));

    return result;
}

myPolynomial myPolynomial::operator-() const
{
    myPolynomial result(*this);

    for (auto& currentTermOfPolynomial : result.listOfTerms)
        currentTermOfPolynomial = -currentTermOfPolynomial;

    return result;
}

bool myPolynomial::operator==(const myPolynomial& other) const
{
    if (this->degree != other.degree or this->listOfTerms.size() != this->listOfTerms.size())
        return false;

    bool result = true;

    auto currentTermOfFirstPolynomial = this->listOfTerms.begin();
    auto currentTermOfSecondPolynomial = other.listOfTerms.begin();

    while (currentTermOfFirstPolynomial != this->listOfTerms.end() and currentTermOfSecondPolynomial != other.listOfTerms.end())
    {
        if (*currentTermOfFirstPolynomial != *currentTermOfSecondPolynomial)
        {
            result = false;
            break;
        }

        currentTermOfFirstPolynomial++;
        currentTermOfSecondPolynomial++;
    }

    if (currentTermOfFirstPolynomial != this->listOfTerms.end() or currentTermOfFirstPolynomial != this->listOfTerms.end())
        result = false;

    return result;
}

bool myPolynomial::operator!=(const myPolynomial& other) const
{
    return !(*this == other);
}

myPolynomial& myPolynomial::operator=(const myPolynomial& other)
{
    if (this == &other)
        return *this;

    this->listOfTerms.assign(other.listOfTerms.begin(), other.listOfTerms.end());
    this->degree = other.degree;

    return *this;
}

myPolynomial& myPolynomial::operator+=(const myPolynomial& other)
{
    *this = *this + other;
    return *this;
}

myPolynomial& myPolynomial::operator-=(const myPolynomial& other)
{
    *this = *this - other;
    return *this;
}

myPolynomial& myPolynomial::operator*=(const myPolynomial& other)
{
    *this = *this * other;
    return *this;
}

myPolynomial& myPolynomial::operator*=(int other)
{
    *this = *this * other;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const myPolynomial& obj)
{
    if (obj == myPolynomial::ZERO)
        return os << 0;

    for (auto currentTermOfPolynomial = obj.listOfTerms.begin(); currentTermOfPolynomial != obj.listOfTerms.end(); currentTermOfPolynomial++)
    {
        if (currentTermOfPolynomial != obj.listOfTerms.begin() and currentTermOfPolynomial->getCoeff() >= 0)
            os << "+";

        os << *currentTermOfPolynomial;
    }

    return os;
}
