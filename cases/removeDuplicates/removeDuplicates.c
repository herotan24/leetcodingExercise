#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize <= 2) {
        return numsSize;
    }
    int slow = 2, fast = 2;
    while (fast < numsSize) {
        if (nums[slow - 2] != nums[fast]) {
            nums[slow] = nums[fast];
            ++slow;
        }
        ++fast;
    }
    return slow;
}

int main() {
    {
        int nums[] = { 1,1,1,2,2,3 };
        assert(5 == removeDuplicates(nums, 6));
        assert(nums[0] == 1);
        assert(nums[1] == 1);
        assert(nums[2] == 2);
        assert(nums[3] == 2);
        assert(nums[4] == 3);
    }

    {
        int nums[] = { 1,1,1,1,1,1 };
        assert(2 == removeDuplicates(nums, 6));
        assert(nums[0] == 1);
        assert(nums[1] == 1);
    }

    return 0;
}
