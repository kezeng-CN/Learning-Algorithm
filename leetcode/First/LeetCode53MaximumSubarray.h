// 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
// 示例:
// 输入: [-2,1,-3,4,-1,2,1,-5,4],
// 输出: 6
// 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
// 进阶:
// 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。

#include <vector>

#include <stdio.h>

namespace MaximumSubarray1
{
using std::vector;
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int max = nums[0];
        int bal = nums[0];
        for (size_t i = 1; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                bal = bal > 0 ? bal + nums[i] : nums[i];
            }
            else if (nums[i] <= 0)
            {
                bal = bal + nums[i] > 0 ? bal + nums[i] : nums[i];
            }
            max = bal > max ? bal : max;
        }
        return max;
    }
};
void test()
{
    int arr_nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int len = sizeof(arr_nums) / sizeof(int);
    vector<int> nums(arr_nums, arr_nums + len);
    Solution obj;
    printf("%d\n", obj.maxSubArray(nums));
}
} // namespace MaximumSubarray1
void MaximumSubarray_test()
{
    MaximumSubarray1::test();
}