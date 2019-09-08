#ifndef DYNAMIC_PROGRAMMING_H
#define DYNAMIC_PROGRAMMING_H

#include <stdio.h>
#include <stdlib.h>

// 数组中不相邻数的最大值
int non_adjacent_numbers_dp_opt(int arr[], int len)
{
    int *opt_arr = (int *)malloc(len * sizeof(int));
    // 统计最优表
    opt_arr[0] = arr[0];
    opt_arr[1] = arr[0] > arr[1] ? arr[0] : arr[1];
    for (size_t i = 2; i < len; i++)
    {
        opt_arr[i] =
            arr[i] + opt_arr[i - 2] > opt_arr[i - 1] ? arr[i] + opt_arr[i - 2] : opt_arr[i - 1];
    }
    return opt_arr[len - 1];
}

int non_adjacent_numbers_rec_opt(int arr[], int len)
{
    if (len == 0)
    {
        return arr[0];
    }
    else if (len == 1)
    {
        return arr[0] > arr[1] ? arr[0] : arr[1];
    }
    return non_adjacent_numbers_rec_opt(arr, len - 2) + arr[len] > non_adjacent_numbers_rec_opt(arr, len - 1) ? non_adjacent_numbers_rec_opt(arr, len - 2) + arr[len] : non_adjacent_numbers_rec_opt(arr, len - 1);
}

void dynamic_programming_test()
{
    int arr[] = {1, 2, 4, 1, 7, 8, 3};
    int len = sizeof(arr) / sizeof(int);
    printf("non_adjacent_numbers_dp_opt\t%d\n", non_adjacent_numbers_dp_opt(arr, len));
    printf("non_adjacent_numbers_rec_opt\t%d\n", non_adjacent_numbers_rec_opt(arr, len));
}

#endif
