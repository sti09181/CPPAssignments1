///////////////////////////
///// Assignment5.hpp /////
///////////////////////////

#pragma once
#include "Libraries.hpp"

namespace Assignment5
{
    void Solution1()
    {
        int countOfOperations;

        std::cin >> countOfOperations;

        for (int currentOperation = 0; currentOperation < countOfOperations; currentOperation++)
        {
            int countOfInputs;

            std::cin >> countOfInputs;

            std::vector<std::vector<char>> matrix(10, std::vector<char>(10, '+'));

            matrix[4][4] = matrix[5][5] = 'O';
            matrix[4][5] = matrix[5][4] = 'X';

            bool isBlack = true;

            char targetChar;

            std::vector<std::pair<int, int>> coordinate =
            {
                { -1, -1  }, { -1, 0  }, { -1, 1  },
                {  0, -1  }, {  0, 0  }, {  0, 1  },
                {  1, -1  }, {  1, 0  }, {  1, 1  }
            };

            int countOfBlack = 2;
            int countOfWhite = 2;

            for (int currentInput = 0; currentInput < countOfInputs; currentInput++)
            {
                int row, col;

                std::cin >> row >> col;

                if (isBlack)
                {
                    targetChar = 'X';
                    countOfBlack++;
                }
                else
                {
                    targetChar = 'O';
                    countOfWhite++;
                }

                matrix[row][col] = targetChar;

                for (auto [targetRow, targetCol] : coordinate)
                {
                    bool isChangeable;

                    int nextRow = targetRow;
                    int nextCol = targetCol;

                    while (true)
                    {
                        if (matrix[row + targetRow][col + targetCol] == '+')
                        {
                            isChangeable = false;
                            break;
                        }

                        if (matrix[row + targetRow][col + targetCol] == targetChar)
                        {
                            isChangeable = true;
                            break;
                        }

                        targetRow += nextRow;
                        targetCol += nextCol;
                    }

                    targetRow = nextRow;
                    targetCol = nextCol;

                    if (isChangeable)
                    {
                        while (matrix[row + targetRow][col + targetCol] != targetChar)
                        {
                            matrix[row + targetRow][col + targetCol] = targetChar;

                            if (isBlack)
                            {
                                countOfBlack++;
                                countOfWhite--;
                            }
                            else
                            {
                                countOfBlack--;
                                countOfWhite++;
                            }

                            targetRow += nextRow;
                            targetCol += nextCol;
                        }
                    }
                }

                isBlack = !isBlack;
            }

            std::cout << countOfBlack << " " << countOfWhite << std::endl;

            std::for_each(matrix.cbegin() + 1, matrix.cend() - 1, [](const std::vector<char>& vector)
            {
                std::for_each(vector.cbegin() + 1, vector.cend() - 1, [](const char& element) { std::cout << element; });
                std::cout << std::endl;
            });
        }
    }

    void Solution2()
    {
        int countOfOperations;

        std::cin >> countOfOperations;

        for (int currentOperation = 0; currentOperation < countOfOperations; currentOperation++)
        {
            int r, s, t;

            std::cin >> r >> s >> t;

            std::vector<std::vector<int>> first(r, std::vector<int>(s, 0));
            std::vector<std::vector<int>> second(s, std::vector<int>(t, 0));
            std::vector<std::vector<int>> result(r, std::vector<int>(t, 0));

            for (int i = 0; i < r; i++)
                for (int j = 0; j < s; j++)
                    std::cin >> first[i][j];

            for (int i = 0; i < s; i++)
                for (int j = 0; j < t; j++)
                    std::cin >> second[i][j];

            for (int i = 0; i < r; i++)
                for (int j = 0; j < t; j++)
                    for (int k = 0; k < s; k++)
                        result[i][j] += first[i][k] * second[k][j];

            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < t; j++)
                    std::cout << result[i][j] << " ";
                std::cout << std::endl;
            }
        }
    }

    void Solution3()
    {
        std::ifstream inputStream("input.txt");

        std::vector<std::string> inputResult;

        while (inputStream)
        {
            std::string inputLine;
            std::getline(inputStream, inputLine);
            inputResult.emplace_back(inputLine);
        }

        int countOfOperations = std::stoi(inputResult[0]);

        for (int currentOperation = 0, currentInputIndex = 1; currentOperation < countOfOperations; currentOperation++, currentInputIndex++)
        {
            int sizeOfMatrix = std::stoi(inputResult[currentInputIndex]);

            std::vector<std::vector<int>> matrix(sizeOfMatrix, std::vector<int>(sizeOfMatrix, 0));

            int row = 0, col = sizeOfMatrix / 2;

            for (int i = 0, count = 1; i < sizeOfMatrix * sizeOfMatrix; i++, count++)
            {
                if (row < 0) row += sizeOfMatrix;
                if (col >= sizeOfMatrix) col -= sizeOfMatrix;

                matrix[row][col] = count;

                if (count % sizeOfMatrix == 0)
                {
                    row++;
                }
                else
                {
                    row--;
                    col++;
                }
            }

            for (auto& vector : matrix)
            {
                for (auto& element : vector)
                    std::cout << element << " ";
                std::cout << std::endl;
            }
        }
    }
}
