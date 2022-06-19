///////////////////////////
///// Assignment4.hpp /////
///////////////////////////

#pragma once
#include "Libraries.hpp"

namespace Assignment4
{
    void Solution1()
    {
        int countOfOperations;

        std::cin >> countOfOperations;

        for (int currentOperation = 0; currentOperation < countOfOperations; currentOperation++)
        {
            std::string target;

            std::cin >> target;

            std::string result;

            while (target.size() != 1)
            {
                int rhs = target.back() - '0';

                result += static_cast<char>(rhs + '0');

                target.pop_back();

                if (rhs == 0)
                    continue;

                int lhs = target.back() - '0';

                if (lhs - rhs < 0)
                {
                    target.back() = static_cast<char>(((10 + lhs) - rhs) + '0');

                    for (std::string::reverse_iterator it = target.rbegin() + 1; it != target.rend(); it++)
                    {
                        if (*it != '0')
                        {
                            if ((*it - '0') - 1 >= 0)
                            {
                                *it = static_cast<char>(*it - 1);
                                break;
                            }
                        }
                        else
                        {
                            *it = '9';
                        }
                    }
                }
                else
                {
                    target.back() = static_cast<char>((lhs - rhs) + '0');
                }
            }

            std::reverse(result.begin(), result.end());

            for (std::string::iterator it = result.begin(); it != result.end(); it++)
            {
                if (*it != '0')
                {
                    result = std::string(it, result.end());
                    break;
                }
            }

            if (std::stoi(target) == 0)
                std::cout << result << std::endl;
            else
                std::cout << 0 << std::endl;
        }
    }

    void Solution2()
    {
        int countOfOperations;

        std::cin >> countOfOperations;

        for (int currentOperation = 0; currentOperation < countOfOperations; currentOperation++)
        {
            std::string name;

            std::cin >> name;

            bool isVaild = true;

            for (std::string::iterator it = name.begin(); it != name.end(); it++)
            {
                if (it == name.begin())
                {
                    if (std::isdigit(*it) or (!std::isalpha(*it) and *it != '_'))
                    {
                        isVaild = false;
                        break;
                    }
                }
                else
                {
                    if (!std::isdigit(*it) and !std::isalpha(*it) and *it != '_')
                    {
                        isVaild = false;
                        break;
                    }
                }
            }

            std::cout << static_cast<int>(isVaild) << std::endl;
        }
    }

    void Solution3()
    {
        int countOfOperations;

        std::cin >> countOfOperations;

        for (int currentOperation = 0; currentOperation < countOfOperations; currentOperation++)
        {
            int year, month, dayOfTheMonth;

            std::cin >> year >> month >> dayOfTheMonth;

            if (month == 1)
            {
                month = 13;
                year--;
            }

            if (month == 2)
            {
                month = 14;
                year--;
            }

            // const auto yearOfTheCentury = year % 100;
            // const auto zeroBasedCentury = std::floor(year / 100);
            // const auto dayOfTheWeek = static_cast<int>(dayOfTheMonth + std::floor((13 * (month + 1)) / 5) + yearOfTheCentury + std::floor(yearOfTheCentury / 4) + std::floor(zeroBasedCentury / 4) - 2 * zeroBasedCentury) % 7;
            // const auto dayOfTheWeek = static_cast<int>(dayOfTheMonth + std::floor((13 * (month + 1)) / 5) + yearOfTheCentury + std::floor(yearOfTheCentury / 4) + std::floor(zeroBasedCentury / 4) + 5 * zeroBasedCentury) % 7;
            // const auto dayOfTheWeek = static_cast<int>(dayOfTheMonth + std::floor((13 * (month + 1)) / 5) + year + std::floor(year / 4) - std::floor(year / 100) + std::floor(year / 400)) % 7;
            // const auto dayOfTheWeekForISOWeekDate = ((dayOfTheWeek + 5) % 7) + 1; // (1 = Monday to 7 = Sunday)

            const auto dayOfTheWeek = static_cast<int>(dayOfTheMonth + std::floor((13 * (month + 1)) / 5) + year + std::floor(year / 4) - std::floor(year / 100) + std::floor(year / 400)) % 7;

            switch (dayOfTheWeek)
            {
                case 0: std::cout << 6 << std::endl; break; // Saturday
                case 1: std::cout << 0 << std::endl; break; // Sunday
                case 2: std::cout << 1 << std::endl; break; // Monday
                case 3: std::cout << 2 << std::endl; break; // Tuesday
                case 4: std::cout << 3 << std::endl; break; // Wednesday
                case 5: std::cout << 4 << std::endl; break; // Thursday
                case 6: std::cout << 5 << std::endl; break; // Friday
                default: break;
            }
        }
    }
}
