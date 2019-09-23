#ifndef LONGEST_PALINDROMIC_SUBSTRING_H
#define LONGEST_PALINDROMIC_SUBSTRING_H

#include <string>

#include <time.h>

#include "../../common/test_case.h"

namespace LongestPalindromicSubstring1
{
using std::string;
class Solution
{
    bool PalindromicSubstring(string s)
    {
        int i = 0, j = s.length() - 1;
        while (i < j)
        {
            if (s[i++] != s[j--])
            {
                return false;
            }
        }
        return true;
    }

public:
    string longestPalindrome(string s)
    {
        string ret;
        for (size_t i = 0; i < s.length(); i++)
        {
            for (size_t j = ret.length(); j <= s.length() - i; j++)
            {
                if (PalindromicSubstring(s.substr(i, j)))
                {
                    ret = s.substr(i, j);
                }
            }
        }
        return ret;
    }
};
void test()
{
    auto t = clock();
    printf("%s\n", Solution().longestPalindrome(LC5LongestPalindromicSubstring).c_str());
    printf("time spent %ld\n", clock() - t);
}
} // namespace LongestPalindromicSubstring1

void LongestPalindromicSubstring_test()
{
    LongestPalindromicSubstring1::test();
}

#endif