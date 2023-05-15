// https://www.codewars.com/kata/55c04b4cc56a697bb0000048

#include <string>
#include <algorithm>

bool scramble(const std::string &s1, const std::string &s2)
{

    std::string sorted_s1 = s1;
    std::string sorted_s2 = s2;

    std::sort(sorted_s1.begin(), sorted_s1.end());
    std::sort(sorted_s2.begin(), sorted_s2.end());

    return std::includes(sorted_s1.begin(), sorted_s1.end(), sorted_s2.begin(), sorted_s2.end());
}