///////////////////////////
///// Assignment3.hpp /////
///////////////////////////

#pragma once
#include "Libraries.hpp"

namespace Assignment3
{
    void Solution1()
    {
        int countOfOperations;

        std::cin >> countOfOperations;

        for (int currentOperation = 0; currentOperation < countOfOperations; currentOperation++)
        {
            int firstBeginRange, firstEndRange;
            int secondBeginRange, secondEndRange;

            std::cin >> firstBeginRange >> firstEndRange >> secondBeginRange >> secondEndRange;

            int firstResult, secondResult;

            firstResult = std::min(firstEndRange, secondEndRange) - std::max(firstBeginRange, secondBeginRange);

            if (firstResult <= 0)
            {
                firstResult = 0;
                secondResult = (firstEndRange - firstBeginRange) + (secondEndRange - secondBeginRange);
            }
            else
            {
                secondResult = std::max(firstEndRange, secondEndRange) - std::min(firstBeginRange, secondBeginRange);
            }

            std::cout << firstResult << " " << secondResult << std::endl;
        }
    }

    void Solution2()
    {
        struct Coordinate
        {
            int LeftBottomX, LeftBottomY;
            int RightTopX, RightTopY;
            int Width, Height;
        };

        int countOfOperations;

        std::cin >> countOfOperations;

        for (int currentOperation = 0; currentOperation < countOfOperations; currentOperation++)
        {
            Coordinate Rect1{};
            Coordinate Rect2{};

            std::cin >> Rect1.LeftBottomX >> Rect1.LeftBottomY >> Rect1.RightTopX >> Rect1.RightTopY;
            std::cin >> Rect2.LeftBottomX >> Rect2.LeftBottomY >> Rect2.RightTopX >> Rect2.RightTopY;

            Rect1.Width = Rect1.RightTopX - Rect1.LeftBottomX;
            Rect2.Width = Rect2.RightTopX - Rect2.LeftBottomX;
            Rect1.Height = Rect1.RightTopY - Rect1.LeftBottomY;
            Rect2.Height = Rect2.RightTopY - Rect2.LeftBottomY;

            int firstResult = (Rect1.Width * Rect1.Height) + (Rect2.Width * Rect2.Height);
            int secondResult = Rect1.Width + Rect1.Width + Rect1.Height + Rect1.Height + Rect2.Width + Rect2.Width + Rect2.Height + Rect2.Height;

            if (Rect1.LeftBottomX < Rect2.RightTopX && Rect1.RightTopX > Rect2.LeftBottomX && Rect1.LeftBottomY < Rect2.RightTopY && Rect1.RightTopY > Rect2.LeftBottomY)
            {
                const int leftBottomX = std::max(Rect1.LeftBottomX, Rect2.LeftBottomX);
                const int leftBottomY = std::max(Rect1.LeftBottomY, Rect2.LeftBottomY);
                const int rightTopX = std::min(Rect1.RightTopX, Rect2.RightTopX);
                const int rightTopY = std::min(Rect1.RightTopY, Rect2.RightTopY);

                const int width = rightTopX - leftBottomX;
                const int height = rightTopY - leftBottomY;

                firstResult -= width * height;
                secondResult -= width + width + height + height;
            }

            std::cout << firstResult << ' ' << secondResult << std::endl;
        }
    }

    void Solution3()
    {
        int countOfOperations;

        std::cin >> countOfOperations;

        for (int currentOperation = 0; currentOperation < countOfOperations; currentOperation++)
        {
            int sizeOfMatrix;

            std::cin >> sizeOfMatrix;

            std::vector<std::vector<char>> matrix(sizeOfMatrix, std::vector<char>(sizeOfMatrix, '.'));

            const int median = sizeOfMatrix / 2;

            for (int row = 0; row < sizeOfMatrix; row++)
            {
                for (int col = 0; col < sizeOfMatrix; col++)
                {
                    if (row == 0 || row == median || row == sizeOfMatrix - 1)
                    {
                        if (col == 0 || col == median || col == sizeOfMatrix - 1)
                            matrix[row][col] = '+';
                        else
                            matrix[row][col] = '-';
                    }
                    else
                    {
                        if (col == 0 || col == median || col == sizeOfMatrix - 1)
                            matrix[row][col] = '|';
                        else
                        {
                            if (col != median)
                            {
                                if (row == col)
                                    matrix[row][col] = '\\';
                                else if (row - median == median - col)
                                    matrix[row][col] = '/';
                            }
                        }
                    }
                }
            }

            matrix[median][median] = '*';

            for (const auto& vector : matrix)
            {
                for (const auto& element : vector)
                    std::cout << element;
                std::cout << std::endl;
            }
        }
    }

    void Solution4()
    {
        int countOfOperations;

        std::cin >> countOfOperations;

        for (int currentOperation = 0; currentOperation < countOfOperations; currentOperation++)
        {
            int countOfNumbers;

            std::cin >> countOfNumbers;

            std::vector<int> numbers(countOfNumbers);

            for (auto& number : numbers)
                std::cin >> number;

            int result = 0;

            bool isDuplicated = false;

            for (int i = 1; i < static_cast<int>(numbers.size()) - 1; i++)
            {
                if (numbers[i - 1] < numbers[i] || isDuplicated)
                {
                    if (numbers[i] == numbers[i + 1])
                    {
                        isDuplicated = true;
                    }
                    else if (numbers[i] > numbers[i + 1])
                    {
                        isDuplicated = false;
                        result++;
                    }
                }
            }

            std::cout << result << std::endl;
        }
    }
}
