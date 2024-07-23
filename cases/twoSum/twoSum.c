#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

// https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/?envType=study-plan-v2&envId=top-interview-150

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int *ret = malloc(sizeof(int) * 2);
    int l = 0;
    int r = numbersSize - 1;
    int sum;

    while (l < r) {
        sum = numbers[l] + numbers[r];
        if (sum == target) {
            ret[0] = l + 1;
            ret[1] = r + 1;
            break;
        } else if (sum < target) {
            l++;
        } else { 
            r--;
        }
    }

    *returnSize = 2;
    return ret;
}

int main() {
    {
        int nums[] = { 2, 3, 4 };
        int numsSize = 3;
        int target = 6;
        int returnSize = 0;
        int *ret = twoSum(&nums[0], numsSize, target, &returnSize);
        assert(ret[0] == 1 && ret[1] == 3);
        free(ret);
    }

    {
        int nums[] = { 2, 7, 11, 15 };
        int numsSize = 4;
        int target = 22;
        int returnSize = 0;
        int *ret = twoSum(&nums[0], numsSize, target, &returnSize);
        assert(ret[0] == 2 && ret[1] == 4);
        free(ret);
    }

    {
        int nums[] = { -1, 0 };
        int numsSize = 2;
        int target = -1;
        int returnSize = 0;
        int *ret = twoSum(&nums[0], numsSize, target, &returnSize);
        assert(ret[0] == 1 && ret[1] == 2);
        free(ret);
    }
    return 0;
}
