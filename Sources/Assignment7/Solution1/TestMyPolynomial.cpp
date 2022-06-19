////////////////////////////////
///// TestMyPolynomial.cpp /////
////////////////////////////////

#include <iostream>

#include "MyPolynomial.h"

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
    std::cout << myPolynomial::ZERO << std::endl;
    std::cout << myPolynomial::ONE << std::endl;
    std::cout << myPolynomial::X << std::endl;

    myPolynomial p0, p1(1), p2(1, 1), p3(3, 5);

    int testData4[10] = { 1, 0, 1, 1, 1, 2, 1, 3, 1, 4 };
    int testData5[10] = { -1, 0, -1, 1, -1, 2, -1, 3, -1, 4 };
    int testData6[10] = { 1, 0, -1, 1, 1, 2, -1, 3, 1, 4 };
    int testData7[10] = { 2, 2, 5, 5, 4, 4, 1, 1, 3, 3 };
    int testData8[12] = { 1, 1000000000, 1, 100000000, 1, 1000000, 1, 10000, 1, 100, 1, 0 };

    myPolynomial p4(5, testData4);
    myPolynomial p5(5, testData5);
    myPolynomial p6(5, testData6);
    myPolynomial p7(5, testData7);
    myPolynomial p8(6, testData8);
    myPolynomial p9(p7);

    // test constructor
    std::cout << p0 << std::endl << p1 << std::endl << p2 << std::endl;
    std::cout << p4 << std::endl << p8 << std::endl;

    // test copy constructor
    std::cout << p9 << std::endl;

    // test accessor function
    std::cout << p8.getDegree() << " " << p8.getNumTerms() << std::endl;

    // test evaluation function
    std::cout << p1(2) << " " << p2(2) << " " << p3(2) << " " << p4(2) << " " << std::endl;
    std::cout << p5(3) << " " << p6(3) << " " << p7(3) << " " << p9(3) << " " << std::endl;

    // test comparison operators
    std::cout << (p7 == p9) << " " << (p7 != p9) << std::endl;

    // test derivative function
    std::cout << myPolynomial::ZERO.ddx() << std::endl;
    std::cout << myPolynomial::ONE.ddx() << std::endl;
    std::cout << myPolynomial::X.ddx() << std::endl;
    std::cout << p4.ddx() << std::endl;
    std::cout << p8.ddx() << std::endl;

    // test unary operator -
    std::cout << -myPolynomial::ZERO << std::endl;
    std::cout << -p4 << std::endl;

    // test k * p(x) or p(x) * k
    std::cout << 3 * myPolynomial::ZERO << std::endl;
    std::cout << 3 * myPolynomial::ONE << std::endl;
    std::cout << myPolynomial::X * 3 << std::endl;
    std::cout << 3 * p4 << " " << p4 * 3 << std::endl;
    std::cout << 0 * p5 << " " << p5 * 5 << std::endl;

    // test binary operator +
    std::cout << p4 + p5 << std::endl;

    // test binary operator -
    std::cout << p6 - p7 << std::endl;

    // test binary operator *
    std::cout << p8 * p9 << std::endl;

    myPolynomial tmp1(p4), tmp2, tmp3, tmp4;
    tmp4 = tmp3 = tmp2 = tmp1;

    std::cout << (tmp1 += p5) << std::endl;
    std::cout << (tmp2 -= p5) << std::endl;
    std::cout << (tmp3 *= p5) << std::endl;
    std::cout << (tmp4 *= 3) << std::endl;
}

void testDataFromFile()
{
    int numTestCases;

    std::cin >> numTestCases;

    for (int i = 0; i < numTestCases; i++)
    {
        int numTerms, terms[100];

        std::cin >> numTerms;
        for (int j = 0; j < numTerms; j++)
            std::cin >> terms[2 * j] >> terms[2 * j + 1];

        myPolynomial p1(numTerms, terms);

        std::cin >> numTerms;
        for (int j = 0; j < numTerms; j++)
            std::cin >> terms[2 * j] >> terms[2 * j + 1];

        myPolynomial p2(numTerms, terms);

        std::cout << p1 << std::endl << p2 << std::endl;
        std::cout << p1.getDegree() << " " << p2.getNumTerms() << std::endl;
        std::cout << p1.ddx() << std::endl << p2.ddx() << std::endl;
        std::cout << (p1 == p2) << " " << (p1 != p2) << std::endl;
        std::cout << p1(1) << std::endl;

        std::cout << -p1 + p1 * 2 * p2 - p2 * 2 + 3 * p1 << std::endl;

        myPolynomial p3(myPolynomial::ZERO), p4(myPolynomial::ONE), p5(myPolynomial::X);
        p3 += p1;
        p4 -= p2;
        p5 *= p4;
        p5 *= 2;

        std::cout << p5 << std::endl;
    }
}
