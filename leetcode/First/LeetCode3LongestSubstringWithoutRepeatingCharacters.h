#ifndef LONGEST_SUBSTRING_WITHOUT_REAPTING_CHARACTERS_H
#define LONGEST_SUBSTRING_WITHOUT_REAPTING_CHARACTERS_H

#include <stdio.h>

#include <set>
#include <string>

using std::set;
using std::string;

namespace LengthOfLongestSubstring1
{
using std::set;
using std::string;
class Solution
{
    bool unique(string s)
    {
        set<char> c_set;
        for (size_t i = 0; i < s.length(); i++)
        {
            if (c_set.find(s[i]) == c_set.end())
            {
                c_set.insert(s[i]);
            }
            else
            {
                return false;
            }
        }
        return true;
    }

public:
    int lengthOfLongestSubstring(string s)
    {
        int i = 0;
        int j = 0;
        int ret = 0;
        for (size_t i = 0; i < s.length(); i++)
        {
            for (size_t j = 0; j <= s.length() - i; j++)
            {
                if (unique(s.substr(i, j)))
                {
                    ret = ret > j ? ret : j;
                }
            }
        }
        return ret;
    }
};
void test()
{
    printf("%d\n", Solution().lengthOfLongestSubstring("pwwkew"));
}
} // namespace LengthOfLongestSubstring1

namespace LengthOfLongestSubstring2
{
using std::set;
using std::string;
class Solution
{
    bool unique(string s)
    {
        set<char> c_set;
        for (size_t i = 0; i < s.length(); i++)
        {
            if (c_set.find(s[i]) == c_set.end())
            {
                c_set.insert(s[i]);
            }
            else
            {
                return false;
            }
        }
        return true;
    }

public:
    int lengthOfLongestSubstring(string s)
    {
        int i = 0;
        int j = 0;
        int ret = 0;
        for (size_t i = 0, j = 0; i + j <= s.length();)
        {
            if (unique(s.substr(i, j)))
            {
                ret = ret > j ? ret : j;
                j++;
            }
            else
            {
                i++;
            }
        }
        return ret;
    }
};
void test()
{
    printf("%d\n", Solution().lengthOfLongestSubstring("pwwkew"));
}
} // namespace LengthOfLongestSubstring2

namespace LengthOfLongestSubstring3
{
using std::set;
using std::string;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int i = 0;
        int j = 0;
        int ret = 0;
        int c_set[128] = {0};
        for (size_t i = 0, j = 0; i < s.length() && j < s.length();)
        {
            if (c_set[s[j]] == 0)
            {
                c_set[s[j]] = 1;
                ret = j - i + 1 > ret ? j - i + 1 : ret;
                j++;
            }
            else
            {
                c_set[s[i]] = 0;
                i++;
            }
        }
        return ret;
    }
};
void test()
{
    printf("%d\n", Solution().lengthOfLongestSubstring("abcabcbb"));
}
} // namespace LengthOfLongestSubstring3

namespace LengthOfLongestSubstring4
{
using std::set;
using std::string;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int i = 0;
        int j = 0;
        int ret = 0;
        int c_set[128] = {0};
        for (size_t i = 0, j = 0; j < s.length(); j++)
        {
            if (c_set[s[j]] > 0)
            {
                i = c_set[s[j]] > i ? c_set[s[j]] : i;
            }
            c_set[s[j]] = j + 1;
            ret = j - i + 1 > ret ? j - i + 1 : ret;
        }
        return ret;
    }
};
void test()
{
    printf("%d\n", Solution().lengthOfLongestSubstring("pwwkew"));
}
} // namespace LengthOfLongestSubstring4

void LengthOfLongestSubstring_test()
{
    LengthOfLongestSubstring1::test();
    LengthOfLongestSubstring2::test();
    LengthOfLongestSubstring3::test();
    LengthOfLongestSubstring4::test();
}

#endif