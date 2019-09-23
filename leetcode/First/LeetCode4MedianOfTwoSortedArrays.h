#ifndef MEDIAN_OF_TWO_SORTED_ARRAYS
#define MEDIAN_OF_TWO_SORTED_ARRAYS

#include <vector>

namespace MedianOfTwoSortedArrays1
{
using std::vector;
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int len = nums1.size() + nums2.size();
        vector<int> nums(len);
        auto it1 = nums1.size() > 0 ? nums1.begin() : nums1.end();
        auto it2 = nums2.size() > 0 ? nums2.begin() : nums2.end();
        int idx = 0;
        while (it1 != nums1.end() && it2 != nums2.end())
        {
            nums[idx++] = *it1 < *it2 ? *it1++ : *it2++;
        }
        while (it1 != nums1.end())
        {
            nums[idx++] = *it1++;
        }
        while (it2 != nums2.end())
        {
            nums[idx++] = *it2++;
        }
        if (len % 2 == 1)
        {
            return nums[len / 2];
        }
        else
        {
            return ((double)nums[(len - 1) / 2] + (double)nums[(len - 1) / 2 + 1]) / 2;
        }
    }
};
void test()
{
    // int arr1[] = {1, 3};
    // int len1 = sizeof(arr1) / sizeof(arr1[0]);
    // int arr2[] = {};
    // int len2 = sizeof(arr2) / sizeof(arr2[0]);
    // vector<int> num1(arr1, arr1 + len1);
    // vector<int> num2(arr2, arr2 + len1);
    vector<int> num1 = {1, 3};
    vector<int> num2 = {2};
    auto output = MedianOfTwoSortedArrays1::Solution().findMedianSortedArrays(num1, num2);
    printf("%lf\n", output);
}
} // namespace MedianOfTwoSortedArrays1

void MedianOfTwoSortedArrays_test()
{
    MedianOfTwoSortedArrays1::test();
}

#endif
