#ifndef WORD_BREAK_H
#define WORD_BREAK_H

// 给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
// 说明：
// 拆分时可以重复使用字典中的单词。
// 你可以假设字典中没有重复的单词。
// 示例 1：
// 输入: s = "leetcode", wordDict = ["leet", "code"]
// 输出: true
// 解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
// 示例 2：
// 输入: s = "applepenapple", wordDict = ["apple", "pen"]
// 输出: true
// 解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
//      注意你可以重复使用字典中的单词。
// 示例 3：
// 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
// 输出: false

#include <string>
#include <vector>

#include <string.h>

namespace wordBreak_1
{
using std::string;
using std::vector;
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        for (size_t i = 0; i < wordDict.size(); i++)
        {
            // 匹配整词
            if (s == wordDict[i])
            {
                return true;
            }
            // 匹配前缀
            string str_prefix = s.substr(0, wordDict[i].size());
            if (str_prefix == wordDict[i])
            {
                // 匹配前缀成功则匹配后缀
                string str_suffix = s.substr(wordDict[i].size(), s.size());
                if (wordBreak(str_suffix, wordDict))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
void test()
{
    string s("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab");
    string char_string_list[] = {"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"};
    int len = sizeof(char_string_list) / sizeof(string);
    vector<string> wordDict = vector<string>(char_string_list, char_string_list + len);
    Solution obj;
    if (obj.wordBreak(s, wordDict))
    {
        printf("true");
    }
    else
    {
        printf("false");
    }
}
} // namespace wordBreak_1

#include <algorithm>
namespace wordBreak_2
{
using std::find;
using std::string;
using std::vector;
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<int> dp_wordbreak(s.size(), 0);
        for (size_t i = 0; i < s.size(); i++)
        {
            // 判断整个字符串
            string str_prefix = s.substr(0, i + 1);
            auto it_word = find(wordDict.begin(), wordDict.end(), str_prefix);
            if (it_word != wordDict.end())
            {
                // 匹配到
                dp_wordbreak[i] = 1;
            }
            else
            {
                // 未匹配
                for (size_t j = 0; j <= i; j++)
                {
                    if (dp_wordbreak[j] == 1)
                    {
                        // 前缀有匹配故匹配后缀
                        str_prefix = s.substr(j + 1, i - j);
                        auto it_word = find(wordDict.begin(), wordDict.end(), str_prefix);
                        if (it_word != wordDict.end())
                        {
                            dp_wordbreak[i] = 1;
                            break;
                        }
                    }
                }
            }
        }
        return dp_wordbreak[s.size() - 1];
    }
};
void test()
{
    string s("applepenapple");
    string char_string_list[] = {"apple", "pen"};
    int len = sizeof(char_string_list) / sizeof(string);
    vector<string> wordDict = vector<string>(char_string_list, char_string_list + len);
    Solution obj;
    if (obj.wordBreak(s, wordDict))
    {
        printf("true");
    }
    else
    {
        printf("false");
    }
}
} // namespace wordBreak_2

void WordBreak_test()
{
    // wordBreak_1::test();
    wordBreak_2::test();
}

#endif