#include "./DynamicProgramming/DynamicProgramming.h"
#include "./leetcode/First/LeetCode3LongestSubstringWithoutRepeatingCharacters.h"
#include "./leetcode/First/LeetCode4MedianOfTwoSortedArrays.h"
#include "./leetcode/First/LeetCode5LongestPalindromicSubstring.h"
#include "./leetcode/First/LeetCode53MaximumSubarray.h"
#include "./leetcode/Second/LeetCode139WordBreak.h"
#include "./leetcode/Second/LeetCode145BinaryTreePostorderTraversal.h"

int main()
{
    LengthOfLongestSubstring_test();     // LeetCode3LengthOfLongestSubstring
    MedianOfTwoSortedArrays_test();      // LeetCode4MediaOfTwoSortedArrays
    LongestPalindromicSubstring_test();  // LeetCode5LongestPalindromicSubstring
    MaximumSubarray_test();              // LeetCode53MaximumSubarray
    WordBreak_test();                    // LeetCode139WordBreak
    BinaryTreePostorderTraversal_test(); // LeetCode145BinaryTreePostorderTraversal
    dynamic_programming_test();          // DynamicProgramming
    return 0;
}
