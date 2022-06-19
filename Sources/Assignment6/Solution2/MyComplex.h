///////////////////////
///// MyComplex.h /////
///////////////////////

#ifndef _MYCOMPLEX_H
#define _MYCOMPLEX_H

#include <iostream>
#include <cstdlib>
#include <cmath>

class myComplex
{
private:
    int real, imag;

public:
    explicit myComplex(int = 0, int = 0) noexcept;
    myComplex(const myComplex&);

    friend myComplex operator+(const myComplex&, const myComplex&);
    friend myComplex operator-(const myComplex&, const myComplex&);
    friend myComplex operator*(const myComplex&, const myComplex&);
    friend myComplex operator+(int, const myComplex&);
    friend myComplex operator-(int, const myComplex&);
    friend myComplex operator*(int, const myComplex&);
    friend myComplex operator+(const myComplex&, int);
    friend myComplex operator-(const myComplex&, int);
    friend myComplex operator*(const myComplex&, int);

    myComplex& operator=(const myComplex&);
    myComplex& operator+=(const myComplex&);
    myComplex& operator-=(const myComplex&);
    myComplex& operator*=(const myComplex&);
    myComplex& operator=(int);
    myComplex& operator+=(int);
    myComplex& operator-=(int);
    myComplex& operator*=(int);

private:
    [[nodiscard]] int norm() const;

public:
    bool operator==(const myComplex&) const;
    bool operator!=(const myComplex&) const;
    bool operator>(const myComplex&) const;
    bool operator>=(const myComplex&) const;
    bool operator<(const myComplex&) const;
    bool operator<=(const myComplex&) const;

    myComplex operator-() const;
    myComplex operator~() const;
    myComplex& operator++();
    myComplex& operator--();
    myComplex operator++(int);
    myComplex operator--(int);

    friend std::ostream& operator<<(std::ostream&, const myComplex&);
    friend std::istream& operator>>(std::istream&, myComplex&);

    void set(int, int);
    void setRealPart(int);
    void setImaginaryPart(int);

    [[nodiscard]] int getRealPart() const;
    [[nodiscard]] int getImaginaryPart() const;
};

#endif
