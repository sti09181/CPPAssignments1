///////////////////////////
///// Assignment2.hpp /////
///////////////////////////

#pragma once
#include "Libraries.hpp"

namespace Assignment2
{
    void Solution1()
    {
        int countOfOperations;

        std::cin >> countOfOperations;

        for (int currentOperation = 0; currentOperation < countOfOperations; currentOperation++)
        {
            std::string number;

            std::cin >> number;

            while (number.size() != 1)
            {
                int temp = 1;

                for (const auto& digit : number)
                {
                    if (digit != '0')
                        temp *= digit - '0';
                }

                number = std::to_string(temp);
            }

            std::cout << number << std::endl;
        }
    }

    void Solution2()
    {
        auto spiralOrder = [](const int sizeOfMatrix, const int startRange, const int endRange) -> std::vector<int>
        {
            std::vector<int> result;

            std::vector<std::vector<int>> matrix(sizeOfMatrix, std::vector<int>(sizeOfMatrix));
            std::vector<std::vector<bool>> seen(sizeOfMatrix, std::vector<bool>(sizeOfMatrix));

            int counter = 1;

            for (auto& vector : matrix)
                for (auto& element : vector)
                    element = counter++;

            const int dr[] = { 0, 1, 0, -1 };
            const int dc[] = { 1, 0, -1, 0 };
            int r = 0, c = 0, di = 0;

            for (int i = 1; i <= sizeOfMatrix * sizeOfMatrix; i++)
            {
                if (i >= startRange and i <= endRange)
                    result.emplace_back(matrix[r][c]);

                seen[r][c] = true;

                const int cr = r + dr[di];
                const int cc = c + dc[di];

                if (0 <= cr and cr < sizeOfMatrix and 0 <= cc and cc < sizeOfMatrix and !seen[cr][cc])
                {
                    r = cr;
                    c = cc;
                }
                else
                {
                    di = (di + 1) % 4;
                    r += dr[di];
                    c += dc[di];
                }
            }

            return result;
        };

        int countOfOperations;

        std::cin >> countOfOperations;

        for (int currentOperation = 0; currentOperation < countOfOperations; currentOperation++)
        {
            int sizeOfMatrix, startRange, endRange;

            std::cin >> sizeOfMatrix >> startRange >> endRange;

            const auto result = spiralOrder(sizeOfMatrix, startRange, endRange);

            for (auto& element : result)
                std::cout << element << " ";
            std::cout << std::endl;
        }
    }

    void Solution3()
    {
        auto spiralOrder = [](const int sizeOfMatrix) -> std::vector<std::vector<int>>
        {
            std::vector<std::vector<int>> matrix(sizeOfMatrix, std::vector<int>(sizeOfMatrix));
            std::vector<std::vector<bool>> seen(sizeOfMatrix, std::vector<bool>(sizeOfMatrix));

            const int dr[] = { 0, 1, 0, -1 };
            const int dc[] = { 1, 0, -1, 0 };
            int r = 0, c = 0, di = 0;

            bool value = ((sizeOfMatrix / 2) % 2 != 0);

            for (int i = 1; i <= sizeOfMatrix * sizeOfMatrix; i++)
            {
                matrix[r][c] = value;
                seen[r][c] = true;

                const int cr = r + dr[di];
                const int cc = c + dc[di];

                if (0 <= cr and cr < sizeOfMatrix and 0 <= cc and cc < sizeOfMatrix and !seen[cr][cc])
                {
                    r = cr;
                    c = cc;
                }
                else
                {
                    if ((di = (di + 1) % 4) == 0)
                        value = !value;

                    r += dr[di];
                    c += dc[di];
                }
            }

            return matrix;
        };

        int countOfOperations;

        std::cin >> countOfOperations;

        for (int currentOperation = 0; currentOperation < countOfOperations; currentOperation++)
        {
            int sizeOfMatrix;

            std::cin >> sizeOfMatrix;

            const auto matrix = spiralOrder(sizeOfMatrix);

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
            std::string number;

            std::cin >> number;

            int result = 0;

            for (const auto& digit : number)
                result += static_cast<int>(std::pow(digit - '0', number.size()));

            if (std::stoi(number) == result)
                std::cout << 1 << std::endl;
            else
                std::cout << 0 << std::endl;
        }
    }
}
