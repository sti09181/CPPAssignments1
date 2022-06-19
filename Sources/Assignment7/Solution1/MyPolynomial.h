//////////////////////////
///// MyPolynomial.h /////
//////////////////////////

#ifndef _MYPOLYNOMIAL_H
#define _MYPOLYNOMIAL_H

#include <iostream>
#include <list>
#include <numeric>
#include <cmath>

#include "MyTerm.h"

class myPolynomial
{
private:
    std::list<myTerm> listOfTerms;
    int degree;

    void sort();

public:
    static const myPolynomial ZERO;
    static const myPolynomial ONE;
    static const myPolynomial X;

    explicit myPolynomial(int = 0, unsigned int = 0u) noexcept;
    myPolynomial(int, int[]) noexcept;

    myPolynomial(const myPolynomial&);

    [[nodiscard]] int getDegree() const;
    [[nodiscard]] int getNumTerms() const;

    [[nodiscard]] myPolynomial ddx() const;

    friend myPolynomial operator+(const myPolynomial& first, const myPolynomial& second);
    friend myPolynomial operator-(const myPolynomial& first, const myPolynomial& second);
    friend myPolynomial operator*(const myPolynomial& first, const myPolynomial& second);

    friend myPolynomial operator*(const myPolynomial& first, int second);
    friend myPolynomial operator*(int first, const myPolynomial& second);

    int operator()(int) const;

    myPolynomial operator-() const;

    bool operator==(const myPolynomial&) const;
    bool operator!=(const myPolynomial&) const;

    myPolynomial& operator=(const myPolynomial&);
    myPolynomial& operator+=(const myPolynomial&);
    myPolynomial& operator-=(const myPolynomial&);
    myPolynomial& operator*=(const myPolynomial&);
    myPolynomial& operator*=(int);

    friend std::ostream& operator<<(std::ostream&, const myPolynomial&);
};

#endif
