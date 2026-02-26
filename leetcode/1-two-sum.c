/*
    https://leetcode.com/problems/two-sum/

    1. Two Sum

    Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

    You may assume that each input would have exactly one solution, and you may not use the same element twice.

    You can return the answer in any order.
*/
#include <stdio.h>
#include <stdlib.h>

// O(n^2) solution
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* resultArr = malloc(2 * sizeof(int));

    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                resultArr[0] = i;
                resultArr[1] = j;
                break;
            }
        }
    }

    *returnSize = 2;
    return resultArr;
}

int main() {
    int arr_size, target;
    // printf("Array size: ");
    scanf("%d", &arr_size);

    int arr[arr_size];
    // printf("Array elements:\n");
    for (int i = 0; i < arr_size; i++) {
        scanf("%d", &arr[i]);
    }

    // printf("Target: ");
    scanf("%d", &target);

    int* result_arr = malloc(2 * sizeof(int));
    int return_size;

    result_arr = twoSum(arr, arr_size, target, &return_size);
    // printf("[%d, %d]\n", result_arr[0], result_arr[1]);
    printf("%d %d\n", result_arr[0], result_arr[1]);

    return 0;
}
