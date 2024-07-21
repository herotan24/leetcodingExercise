#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//void moveZeroes(int* nums, int numsSize)
//{
//    int h = 0;
//    int i;
//
//    for (i = 0; i < numsSize; i++) {
//        if (nums[i] != 0) {
//            nums[h] = nums[i];
//            h++;
//        }
//    }
//
//    for (; h < numsSize; h++) {
//        nums[h] = 0;
//    }
//}

void moveZeroes(int* nums, int numsSize)
{
    int left = 0;
    int right = 0;
    int tmp;

    for (; right < numsSize; right++) {
        if (nums[right]) {
            tmp = nums[right];
            nums[right] = nums[left];
            nums[left] = tmp;
            left++;
        }
    }
}

/*                    h
 *                    l
        int nums[] = {0,1,0,3,2};
                      h l
        int nums[] = {0,1,0,3,2};
        int nums[] = {1,0,0,3,2};

        int nums[] = {1,3,0,0,2};
        int nums[] = {1,3,2,0,0};

                        l r
        int nums[] = {1,3,0,12,0};
        */

int main()
{
    {
        int nums[] = {0,1,0,3,12};
        int numsSize = sizeof(nums) / sizeof(nums[0]);
        moveZeroes(nums, numsSize);

        assert(nums[0] == 1);
        assert(nums[1] == 3);
        assert(nums[2] == 12);
        assert(nums[3] == 0);
        assert(nums[4] == 0);
    }

    {
        int nums[] = {0};
        int numsSize = sizeof(nums) / sizeof(nums[0]);
        moveZeroes(nums, numsSize);

        assert(nums[0] == 0);
    }

    {
        int nums[] = {1, 2};
        int numsSize = sizeof(nums) / sizeof(nums[0]);
        moveZeroes(nums, numsSize);

        assert(nums[0] == 1);
        assert(nums[1] == 2);
    }
}
