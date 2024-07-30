#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

void heap_sift_down(int nums[], int size, int parent) {
    int left, right, largest, tmp;

    left = parent * 2 + 1;
    right = parent * 2 + 2;
    largest = parent;

    if (left < size && nums[left] > nums[parent])
        largest = left;
    if (right < size && nums[right] > nums[largest])
        largest = right;
    if (largest != parent) {
        tmp = nums[largest];
        nums[largest] = nums[parent];
        nums[parent] = tmp;

        heap_sift_down(nums, size, largest);
    }
}

void heap_sort(int nums[], int size) {
    int tmp;

    /* 建立大根堆 */
    for (int last_parent = (size / 2) - 1; last_parent >=0; last_parent--) {
        heap_sift_down(nums, size, last_parent);
    }

    for (int i = size - 1; i >= 0; i--) {
        tmp = nums[0];
        nums[0] = nums[i];
        nums[i] = tmp;
        heap_sift_down(nums, i, 0);
    }
}

int main() {
    {
        int nums[] = { 3, 9, 2, 1, 4, 5 };
        heap_sort(nums, sizeof(nums) / sizeof(int));
        assert(nums[0] == 1);
        assert(nums[1] == 2);
        assert(nums[2] == 3);
        assert(nums[3] == 4);
        assert(nums[4] == 5);
        assert(nums[5] == 9);
    }

    {
        int nums[] = { -1000, 9, 2, 1, 4, 5, 10000 };
        heap_sort(nums, sizeof(nums) / sizeof(int));
        assert(nums[0] == -1000);
        assert(nums[1] == 1);
        assert(nums[2] == 2);
        assert(nums[3] == 4);
        assert(nums[4] == 5);
        assert(nums[5] == 9);
        assert(nums[6] == 10000);
    }

    {
        int nums[] = { 1,1,1,1,1,1,1,1,1,1,1,1,1, 0 };
        heap_sort(nums, sizeof(nums) / sizeof(int));
        assert(nums[0] == 0);
        assert(nums[1] == 1);
        assert(nums[2] == 1);
        assert(nums[3] == 1);
        assert(nums[4] == 1);
        assert(nums[5] == 1);
        assert(nums[6] == 1);
        assert(nums[7] == 1);
        assert(nums[8] == 1);
        assert(nums[9] == 1);
        assert(nums[10] == 1);
        assert(nums[11] == 1);
        assert(nums[12] == 1);
        assert(nums[13] == 1);
    }

    {
        int nums[] = { 0,1,1,1,1,1,1,1,1,1,1,1,1,1 };
        heap_sort(nums, sizeof(nums) / sizeof(int));
        assert(nums[0] == 0);
        assert(nums[1] == 1);
        assert(nums[2] == 1);
        assert(nums[3] == 1);
        assert(nums[4] == 1);
        assert(nums[5] == 1);
        assert(nums[6] == 1);
        assert(nums[7] == 1);
        assert(nums[8] == 1);
        assert(nums[9] == 1);
        assert(nums[10] == 1);
        assert(nums[11] == 1);
        assert(nums[12] == 1);
        assert(nums[13] == 1);
    }

    {
        int nums[] = { 1,1,1,1,1,1,1,0,1,1,1,1,1,1 };
        heap_sort(nums, sizeof(nums) / sizeof(int));
        assert(nums[0] == 0);
        assert(nums[1] == 1);
        assert(nums[2] == 1);
        assert(nums[3] == 1);
        assert(nums[4] == 1);
        assert(nums[5] == 1);
        assert(nums[6] == 1);
        assert(nums[7] == 1);
        assert(nums[8] == 1);
        assert(nums[9] == 1);
        assert(nums[10] == 1);
        assert(nums[11] == 1);
        assert(nums[12] == 1);
        assert(nums[13] == 1);
    }

    return 0;
}
