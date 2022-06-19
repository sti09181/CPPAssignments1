////////////////////
///// MyTerm.h /////
////////////////////

#ifndef _MYTERM_H
#define _MYTERM_H

#include <iostream>

class myPolynomial;

class myTerm
{
private:
    int mCoeff;
    unsigned int mExp;

public:
    explicit myTerm(int = 0, unsigned int = 0) noexcept;
    myTerm(const myTerm&);

    [[nodiscard]] int getCoeff() const;
    [[nodiscard]] unsigned int getExp() const;

    void setCoeff(int);
    void setExp(unsigned int);

    [[nodiscard]] myTerm ddx() const;

    bool operator<(const myTerm&) const;
    bool operator==(const myTerm&) const;
    bool operator!=(const myTerm&) const;

    myTerm operator-() const;

    friend std::ostream& operator<<(std::ostream&, const myTerm&);

    myTerm& operator=(const myTerm&);

    friend myPolynomial;
};

#endif
