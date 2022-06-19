////////////////////////
///// MyRational.h /////
////////////////////////

#ifndef _MYRATIONAL_H
#define _MYRATIONAL_H

#include <iostream>
#include <numeric>
#include <utility>

class myRational
{
private:
    struct Data
    {
        int num = 0;
        int den = 1;
    } data;

    void reduce();

    static std::tuple<myRational::Data, myRational::Data> toCommonDenominator(const myRational::Data&, const myRational::Data&);

public:
    explicit myRational(int = 0, int = 1) noexcept;
    myRational(const myRational&);

    int getNumerator() const;
    int getDenominator() const;

    myRational reciprocal() const;

    friend myRational operator+(const myRational&, const myRational&);
    friend myRational operator-(const myRational&, const myRational&);
    friend myRational operator*(const myRational&, const myRational&);
    friend myRational operator/(const myRational&, const myRational&);

    friend myRational operator+(const myRational&, int);
    friend myRational operator-(const myRational&, int);
    friend myRational operator*(const myRational&, int);
    friend myRational operator/(const myRational&, int);

    friend myRational operator+(int, const myRational&);
    friend myRational operator-(int, const myRational&);
    friend myRational operator*(int, const myRational&);
    friend myRational operator/(int, const myRational&);

    myRational& operator++();
    myRational operator++(int);
    myRational& operator--();
    myRational operator--(int);

    myRational operator-() const;

    friend bool operator<(const myRational&, const myRational&);
    friend bool operator<=(const myRational&, const myRational&);
    friend bool operator>(const myRational&, const myRational&);
    friend bool operator>=(const myRational&, const myRational&);
    friend bool operator==(const myRational&, const myRational&);
    friend bool operator!=(const myRational&, const myRational&);

    friend bool operator<(const myRational&, int);
    friend bool operator<=(const myRational&, int);
    friend bool operator>(const myRational&, int);
    friend bool operator>=(const myRational&, int);
    friend bool operator==(const myRational&, int);
    friend bool operator!=(const myRational&, int);

    friend bool operator<(int, const myRational&);
    friend bool operator<=(int, const myRational&);
    friend bool operator>(int, const myRational&);
    friend bool operator>=(int, const myRational&);
    friend bool operator==(int, const myRational&);
    friend bool operator!=(int, const myRational&);

    myRational& operator=(const myRational&);
    myRational& operator+=(const myRational&);
    myRational& operator-=(const myRational&);
    myRational& operator*=(const myRational&);
    myRational& operator/=(const myRational&);

    myRational& operator=(int);
    myRational& operator+=(int);
    myRational& operator-=(int);
    myRational& operator*=(int);
    myRational& operator/=(int);

    friend std::ostream& operator<<(std::ostream&, const myRational&);
    friend std::istream& operator>>(std::istream&, myRational&);
};

#endif
