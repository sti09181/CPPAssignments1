///////////////////////////
///// TestMyPoint.cpp /////
///////////////////////////

#include <iostream>
#include "MyPoint.h"

int main()
{
    int numTestCases;

    std::cin >> numTestCases;

    for (int i = 0; i < numTestCases; i++)
    {
        int coordX, coordY;

        std::cin >> coordX >> coordY;
        MyPoint p1(coordX, coordY);

        std::cin >> coordX >> coordY;
        MyPoint p2(coordX, coordY);

        if (p1 == p2)
            std::cout << "1" << " ";
        if (p1 != p2)
            std::cout << "0" << " ";

        std::cout << p1.dist2sqr(p2) << " " << p1.dist1(p2) << " ";

        coordX = p1.getX();
        coordY = p1.getY();

        MyPoint p3(p1);

        p3.setX(coordY);
        p3.setY(coordX);

        std::cout << p1.dist2sqr(p3) << " " << p1.dist1(p3) << std::endl;
    }

    return 0;
}
