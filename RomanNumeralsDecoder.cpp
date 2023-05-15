// https://www.codewars.com/kata/51b6249c4612257ac0000005

#include <iostream>
#include <string>
#include <map>

int solution(std::string roman)
{
    int solution{};
    std::map<char, int> map_num{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

    for (int i = 0; i < roman.size(); ++i)
    {
        if (map_num[roman[i]] < map_num[roman[i + 1]]) // check numeral is smaller than next
        {                                 
            solution -= map_num[roman[i]]; // subtract numeral from the solution
        }
        else
        {
            solution += map_num[roman[i]]; // add the current numeral to the solution
        }
    }
    return solution;
}