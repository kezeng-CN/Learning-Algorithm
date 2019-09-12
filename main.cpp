#include <stdio.h>
#include <string>

#include "./DynamicProgramming/DynamicProgramming.h"
#include "./leetcode/First/LeetCode53MaximumSubarray.h"
#include "./leetcode/Second/LeetCode139WordBreak.h"
#include "./leetcode/Second/LeetCode145BinaryTreePostorderTraversal.h"

using std::string;

int main()
{
    MaximumSubarray_test(); // LeetCode53MaximumSubarray
    WordBreak_test();       // LeetCode139WordBreak
    BinaryTreePostorderTraversal_test();
    // dynamic_programming_test();
    return 0;
}
