/////////////////////
///// MyPoint.h /////
/////////////////////

#ifndef _MYPOINT_H
#define _MYPOINT_H

#include <iostream>
#include <cmath>

class MyPoint
{
private:
    int x, y;

public:
    explicit MyPoint(int = 0, int = 0) noexcept;
    MyPoint(const MyPoint&);

    int getX() const;
    int getY() const;

    void setX(int);
    void setY(int);

    bool operator==(const MyPoint&) const;
    bool operator!=(const MyPoint&) const;

    int dist2sqr(const MyPoint&) const;
    int dist1(const MyPoint&) const;
};

#endif
