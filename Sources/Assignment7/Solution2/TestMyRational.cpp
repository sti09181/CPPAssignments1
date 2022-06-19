//////////////////////////////
///// TestMyRational.cpp /////
//////////////////////////////

#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <vector>

#include "MyRational.h"

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
    myRational frac1(2), frac2(3, 2), frac3(6, 4), frac4(12, 8), frac5, frac6, frac7;

    std::cout << frac1 << " " << frac2 << " " << frac3 << " " << frac4 << " " << frac5 << std::endl;
    std::cout << frac1.getNumerator() << " " << frac1.getDenominator() << std::endl;

    std::cout << frac1 * frac2 << " " << frac1 + frac3 << " " << frac2 - frac1 << " " << frac3 / frac2 << std::endl;

    std::cout << ((frac1 < frac2) ? 1 : 0) << " "
         << ((frac1 <= frac2) ? 1 : 0) << " "
         << ((frac1 > frac2) ? 1 : 0) << " "
         << ((frac1 >= frac2) ? 1 : 0) << " "
         << ((frac1 == frac2) ? 1 : 0) << " "
         << ((frac1 != frac2) ? 1 : 0) << " "
         << ((frac2 < frac3) ? 1 : 0) << " "
         << ((frac2 <= frac3) ? 1 : 0) << " "
         << ((frac2 > frac3) ? 1 : 0) << " "
         << ((frac2 >= frac3) ? 1 : 0) << " "
         << ((frac2 == frac3) ? 1 : 0) << " "
         << ((frac2 != frac3) ? 1 : 0) << std::endl;

    std::cout << (frac6 = frac3) << " ";
    std::cout << (frac6 += frac3) << " ";
    std::cout << (frac6 -= frac3) << " ";
    std::cout << (frac6 *= frac3) << " ";
    std::cout << (frac6 /= frac3) << std::endl;

    std::cout << -frac6 << std::endl;

    frac6 = (++frac4) + 2;
    frac7 = 2 + (frac4++);
    std::cout << frac4 << " " << frac6 << " " << frac7 << std::endl;

    frac6 = (--frac4) - 2;
    frac7 = 2 - (frac4--);
    std::cout << frac4 << " " << frac6 << " " << frac7 << std::endl;

    std::cout << 2 * frac3 << " " << frac3 * 2 << " "
         << 2 / frac3 << " " << frac3 / 2 << std::endl;
}

void testDataFromFile()
{
    std::ifstream inputStream("input.txt");

    int countOfOperations;

    inputStream >> countOfOperations;

    for (int currentOperation = 0; currentOperation < countOfOperations; currentOperation++)
    {
        int countOfRationals;

        inputStream >> countOfRationals;

        std::vector<myRational> rationals(countOfRationals);

        for (auto& currentRational : rationals)
            inputStream >> currentRational;

        std::sort(rationals.begin(), rationals.end());

        for (auto& currentRational : rationals)
            std::cout << currentRational << " ";
        std::cout << std::endl;
    }
}
