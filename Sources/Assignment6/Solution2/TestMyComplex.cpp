 /////////////////////////////
///// TestMyComplex.cpp /////
/////////////////////////////

#include <iostream>
#include <cstdlib>
#include <fstream>

#include "MyComplex.h"

void testSimpleCase();
void testDataFromFile();

int main()
{
    testSimpleCase();
    testDataFromFile();

    return EXIT_SUCCESS;
}

void testSimpleCase()
{
    myComplex c0, c1(1), c2(2, 2);
    myComplex c3(c2);
    myComplex c4, c5, c6, c7, c8, c9;
    std::cout << c0 << std::endl << c1 << std::endl << c2 << std::endl;
    std::cout << c3 << std::endl;
    std::cout << c3 << std::endl;
    c3.set(3, 3);
    std::cout << c3 << std::endl;
    c3.setRealPart(4);
    std::cout << c3 << std::endl;
    c3.setImaginaryPart(4);
    std::cout << c3 << std::endl;
    c4 = c1 + c3;
    c5 = c1 - c3;
    c6 = c4 * c5;
    std::cout << c4 << std::endl << c5 << std::endl << c6 << std::endl;
    c7 = c6 + 2;
    c8 = c6 - 2;
    c9 = c6 * 2;
    std::cout << c7 << std::endl << c8 << std::endl << c9 << std::endl;
    c7 += c4;
    c8 -= c5;
    c9 *= c6;
    std::cout << c7 << std::endl << c8 << std::endl << c9 << std::endl;
    c7 += 2;
    c8 -= 2;
    c9 *= 2;
    std::cout << c7 << std::endl << c8 << std::endl << c9 << std::endl;
    std::cout << (c8 != c9) << " " << (c8 == c9) << std::endl;
    std::cout << (c8 > c9) << " " << (c8 >= c9) << " " << (c8 < c9) << " " << (c8 <= c9) << std::endl;
    c7 = c8 = c9;
    std::cout << (c8 != c9) << " " << (c8 == c9) << std::endl;
    std::cout << (c8 > c9) << " " << (c8 >= c9) << " " << (c8 < c9) << " " << (c8 <= c9) << std::endl;
    c7 = -myComplex(2, 3);
    c8 = (++c7) * 2;
    c9 = 2 * (c7++);
    std::cout << c7 << " " << c8 << " " << c9 << std::endl;
    c7 = ~myComplex(2, 3);
    c8 = (--c7) * 2;
    c9 = 2 * (c7--);
    std::cout << c7 << " " << c8 << " " << c9 << std::endl;
    c1 = myComplex(1,2);
    c2 = myComplex(2,3);
    c3 = myComplex(4,5);
    c4 = myComplex(5,6);
    c5 = myComplex(6,7);
    c6 = 3;
    std::cout << -(c1 * c2) - 2 * c3 + ~c4 * c5 * 3 + 2 - c6 << std::endl;
}

void testDataFromFile()
{
    std::ifstream inStream("input.txt");

    if (inStream.fail())
    {
        std::cerr << "Input file opening failed.\n";
        exit(EXIT_FAILURE);
    }

    int numTestCases;
    inStream >> numTestCases;

    for (int i = 0; i < numTestCases; i++)
    {
        myComplex c1, c2, c3, c4;
        myComplex c5, c6, c7, c8, c9;
        inStream >> c1 >> c2 >> c3 >> c4;
        std::cout << c1 << " " << c2 << " " << c3 << " " << c4 << std::endl;
        std::cout << (2 + c1 + 3) + (2 - c2 - 3) * (2 * c3 * 3) - (2 * c4 - 3) << std::endl;
        c5 = c6 = c7 = c8 = c1;
        std::cout << (c5 == c2) << " " << (c5 != c2) << std::endl;
        std::cout << (c5 > c2) << " " << (c5 >= c2) << " " << (c5 < c2) << " " << (c5 <= c2) << std::endl;
        std::cout << (c5 == c6) << " " << (c5 != c6) << std::endl;
        std::cout << (c5 > c6) << " " << (c5 >= c6) << " " << (c5 < c6) << " " << (c5 <= c6) << std::endl;
        c5 += c2;
        c6 -= c3;
        c7 *= c4;
        c8 = c2.getRealPart();
        c9 = c3.getImaginaryPart();
        std::cout << c5 << " " << c6 << " " << c7 << " " << c8 << " " << c9 << std::endl;
        c7 = -c6;
        c8 = (++c7) * 2;
        c9 = 2 * (c7++);
        std::cout << c7 << " " << c8 << " " << c9 << std::endl;
        c7 = ~c6;
        c8 = (++c7) * 2;
        c9 = 2 * (c7++);
        std::cout << c7 << " " << c8 << " " << c9 << std::endl;
    }

    inStream.close();
}
