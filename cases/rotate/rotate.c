#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

// 1,2,3,4,5,6,7,   k = 3
// 7,1,2,3,4,5,6
// 6,7,1,2,3,4,5
// 5,6,7,1,2,3,4

/*
void swap(int* a, int* b) {
    int t = *a;
    *a = *b, *b = t;
}

void reverse(int* nums, int start, int end) {
    while (start < end) {
        swap(&nums[start], &nums[end]);
        start += 1;
        end -= 1;
    }
}

void rotate(int* nums, int numsSize, int k) {
    k %= numsSize;
    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, numsSize - 1);
}

 */

static inline int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void rotate(int* nums, int numsSize, int k) {
    k = k % numsSize;
    int count = gcd(numsSize, k);
    for (int i = 0; i < count; i++) {
        int start = i;
        int curr = i;
        int next;
        int curr_val = nums[curr];
        do {
            next = (curr + k) % numsSize;
            int tmp = nums[next];
            nums[next] = curr_val;
            curr = next;
            curr_val = tmp;
        } while (next != start);
            
    }
}

int main()
{
    {
        int nums[] = { 1,2,3,4,5,6,7 };
        int k = 3;
        rotate(nums, sizeof(nums) / sizeof(int), k);
        assert(nums[0] == 5);
        assert(nums[1] == 6);
        assert(nums[2] == 7);
        assert(nums[3] == 1);
        assert(nums[4] == 2);
        assert(nums[5] == 3);
        assert(nums[6] == 4);
    }
}
