///////////////////////
///// MyPoint.cpp /////
///////////////////////

#include "MyPoint.h"

MyPoint::MyPoint(const int coordX, const int coordY) noexcept
{
    this->x = coordX;
    this->y = coordY;
}

MyPoint::MyPoint(const MyPoint& other)
{
    if (this == &other)
        return;

    this->x = other.x;
    this->y = other.y;
}

int MyPoint::getX() const
{
    return this->x;
}

int MyPoint::getY() const
{
    return this->y;
}

void MyPoint::setX(const int coordX)
{
    this->x = coordX;
}

void MyPoint::setY(const int coordY)
{
    this->y = coordY;
}

bool MyPoint::operator==(const MyPoint& other) const
{
    return (this->x == other.x) and (this->y == other.y);
}

bool MyPoint::operator!=(const MyPoint& other) const
{
    return !(*this == other);
}

int MyPoint::dist2sqr(const MyPoint& other) const
{
    auto distX = std::pow(this->x - other.x, 2);
    auto distY = std::pow(this->y - other.y, 2);

    return static_cast<int>(distX + distY);
}

int MyPoint::dist1(const MyPoint& other) const
{
    auto distX = std::abs(this->x - other.x);
    auto distY = std::abs(this->y - other.y);

    return distX + distY;
}
