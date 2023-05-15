// https://www.codewars.com/kata/5254ca2719453dcc0b00027d

#include <string>
#include <algorithm>
#include <vector>

std::vector<std::string> permutations(std::string s)
{
    std::vector<std::string> permutations_vec;
    std::sort(s.begin(), s.end());
    do
    {
        permutations_vec.push_back(s);
    } while (std::next_permutation(s.begin(), s.end()));
    return permutations_vec;
}