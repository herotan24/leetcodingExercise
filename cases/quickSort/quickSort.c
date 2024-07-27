#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int partition(int *nums, int low, int high) {
    int k = nums[high];
    int i = low - 1;
    int tmp;

    for (int j = low; j <= high - 1; j++) {
        if (nums[j] < k) {
            i++;
            tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
    }

    i++;
    tmp = nums[i];
    nums[i] = nums[high];
    nums[high] = tmp;

    return i;
}

void quick_sort(int *nums, int low, int high) {
    if (low < high) {
        int k = partition(nums, low, high);

        quick_sort(nums, 0, k - 1);
        quick_sort(nums, k + 1, high);
    }
}

int main() {
    {
        int nums[] = {5, 4, 3, 2, 1, 0};
        quick_sort(nums, 0, sizeof(nums) / sizeof(nums[0]) - 1);
        assert(nums[0] == 0);
        assert(nums[1] == 1);
        assert(nums[2] == 2);
        assert(nums[3] == 3);
        assert(nums[4] == 4);
        assert(nums[5] == 5);
    }

    {
        int nums[] = {5, 4, 8, 2, 1, 0};
        quick_sort(nums, 0, sizeof(nums) / sizeof(nums[0]) - 1);
        assert(nums[0] == 0);
        assert(nums[1] == 1);
        assert(nums[2] == 2);
        assert(nums[3] == 4);
        assert(nums[4] == 5);
        assert(nums[5] == 8);
    }

    {
        int nums[] = {5, 4, 8, 2, 1, 9};
        quick_sort(nums, 0, sizeof(nums) / sizeof(nums[0]) - 1);
        assert(nums[0] == 1);
        assert(nums[1] == 2);
        assert(nums[2] == 4);
        assert(nums[3] == 5);
        assert(nums[4] == 8);
        assert(nums[5] == 9);
    }
    return 0;
}
