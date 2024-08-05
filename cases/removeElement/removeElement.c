#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int removeElement(int* nums, int numsSize, int val) {
    int left = 0;
    for (int right = 0; right < numsSize; right++) {
        if (nums[right] != val) {
            nums[left] = nums[right];
            left++;
        }
    }
    return left;
}

int main() {
    {
        int nums[] = { 3,2,2,3 };
        assert(removeElement(&nums[0], 4, 3) == 2);
        assert(nums[0] == 2);
        assert(nums[1] == 2);
    }

    {
        int nums[] = { 0,1,2,2,3,0,4,2 };
        assert(removeElement(&nums[0], 8, 2) == 5);
        assert(nums[0] == 0);
        assert(nums[1] == 1);
        assert(nums[2] == 3);
        assert(nums[3] == 0);
        assert(nums[4] == 4);
    }
    return 0;
}
