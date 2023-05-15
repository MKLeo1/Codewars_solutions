// https://www.codewars.com/kata/51b66044bce5799a7f000003

#include <string>
#include <map>

class RomanHelper
{
public:
    std::map<char, unsigned int> map = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    std::string to_roman(unsigned int n)
    {
        if (n == 0)
            return "";
        if (n >= 1000)
            return "M" + to_roman(n - 1000);
        if (n >= 900)
            return "CM" + to_roman(n - 900);
        if (n >= 500)
            return "D" + to_roman(n - 500);
        if (n >= 400)
            return "CD" + to_roman(n - 400);
        if (n >= 100)
            return "C" + to_roman(n - 100);
        if (n >= 90)
            return "XC" + to_roman(n - 90);
        if (n >= 50)
            return "L" + to_roman(n - 50);
        if (n >= 40)
            return "XL" + to_roman(n - 40);
        if (n >= 10)
            return "X" + to_roman(n - 10);
        if (n >= 9)
            return "IX" + to_roman(n - 9);
        if (n >= 5)
            return "V" + to_roman(n - 5);
        if (n >= 4)
            return "IV" + to_roman(n - 4);
        if (n >= 1)
            return "I" + to_roman(n - 1);
    }

    int from_roman(std::string rn)
    {
        int result{};
        for (unsigned int i = 0; i < rn.size(); ++i)
        {
            if (i + 1 < rn.size() && map[rn[i]] < map[rn[i + 1]])
            {
                result -= map[rn[i]];
            }
            else
            {
                result += map[rn[i]];
            }
        }
        return result;
    }
} RomanNumerals;