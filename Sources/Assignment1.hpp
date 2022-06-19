///////////////////////////
///// Assignment1.hpp /////
///////////////////////////

#pragma once
#include "Libraries.hpp"

namespace Assignment1
{
    void Solution1()
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

            unsigned long long multiplied = 1;

            for (const auto& number : numbers)
            {
                multiplied *= number;
                multiplied %= 10;
            }

            std::cout << multiplied << std::endl;
        }
    }

    void Solution2()
    {
        int countOfOperations;

        std::cin >> countOfOperations;

        for (int currentOperation = 0; currentOperation < countOfOperations; currentOperation++)
        {
            int hours, minutes;

            std::cin >> hours >> minutes;

            const double angleOfHours = 0.5 * ((hours * 60) + minutes);
            const double angleOfMinutes = 6 * minutes;

            double angle = std::abs(angleOfHours - angleOfMinutes);

            angle = std::min(angle, 360 - angle);

            std::cout << static_cast<int>(angle) << std::endl;
        }
    }

    void Solution3()
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

            const auto [min, max] = std::minmax_element(numbers.begin(), numbers.end());

            std::cout << *max << " " << *min << std::endl;
        }
    }

    void Solution4()
    {
        int countOfOperation;

        std::cin >> countOfOperation;

        for (int i = 0; i < countOfOperation; i++)
        {
            int countOfNumbers;

            std::cin >> countOfNumbers;

            std::vector<int> numbers(countOfNumbers);

            for (auto& number : numbers)
                std::cin >> number;

            const int result = std::accumulate(numbers.begin(), numbers.end(), 0);

            std::cout << result << std::endl;
        }
    }
}
