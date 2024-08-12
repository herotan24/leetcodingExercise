#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int hIndex1(int *nums, int size)
{
    int h = 0;

    qsort(nums, size, sizeof(nums[0]), cmp);
    for (int i = size - 1; i >= 0; i--) {
        if (nums[i] > h) {
            h++;
            continue;
        }
        break;
    }

    return h;
}

int hIndex(int *nums, int size)
{
    int rec[1 + 5000] = {0};

    memset(&rec, 0, sizeof(rec));
    for (int i = 0; i < size; i++) {
        if (nums[i] >= size) {
            rec[size]++;
        } else {
            rec[nums[i]]++;
        }
    }

    int tot = 0;
    for (int i = size; i >= 0; i--) {
        tot += rec[i];
        if (tot >= i)
            return i;
    }

    return 0;
}

int main() {

    {
        int nums[] = {1};
        assert(hIndex(nums, sizeof(nums) / sizeof(nums[0])) == 1);
    }

    {
        int nums[] = {3,0,6,1,5};
        assert(hIndex(nums, sizeof(nums) / sizeof(nums[0])) == 3);
    }

    {
        int nums[] = {1,3,1};
        assert(hIndex(nums, sizeof(nums) / sizeof(nums[0])) == 1);
    }

    return 0;
}
