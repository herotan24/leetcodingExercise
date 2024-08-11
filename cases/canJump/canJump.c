#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

bool canJump(int* nums, int numsSize) {
    int rightmost = 0;

    for (int i = 0; i < numsSize; i++) {
        if (i <= rightmost) {
            rightmost = max(rightmost, i + nums[i]);
            if (rightmost >= (numsSize - 1)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    {
        int nums[] = {2,3,1,1,4};
        assert(canJump(nums, 5) == true);
    }

    {
        int nums[] = {3,2,1,0,4};
        assert(canJump(nums, 5) == false);
    }

    {
        int nums[] = {0};
        assert(canJump(nums, 1) == true);
    }

    {
        int nums[] = {0,1};
        assert(canJump(nums, 2) == false);
    }

    {
        int nums[] = {1,0};
        assert(canJump(nums, 2) == true);
    }

    {
        int nums[] = {2,0,0};
        assert(canJump(nums, 3) == true);
    }

    {
        int nums[] = {2,0,0,0};
        assert(canJump(nums, 4) == false);
    }

    return 0;
}
