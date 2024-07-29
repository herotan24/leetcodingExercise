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

void findK(int *nums, int low, int high, int K) {
    if (low < high) {
        int pviot = partition(nums, low, high);

        if (pviot == K) return;
        if (pviot > K)
            findK(nums, low, pviot - 1, K);
        else
            findK(nums, pviot + 1, high, K);
    }


}

int findKthLargest(int* nums, int numsSize, int k) {

    int K = ((numsSize - 1) - k) + 1;
    findK(nums, 0, numsSize - 1, K);
    
    return nums[K];
}

/*                 K       4 3 2 1
 *                         h-k+1
 *                     l p K p   h
        int nums[] = { 3,2,1,5,6,4 };
        */

int main() {
    {
        int nums[] = { 3,2,1 };
        assert(findKthLargest(nums, sizeof(nums) / sizeof(nums[0]), 1) == 3);
    }

    {
        int nums[] = { 3,2,1,5,6,4 };
        assert(findKthLargest(nums, sizeof(nums) / sizeof(nums[0]), 2) == 5);
    }

    {
        int nums[] = { 3,2,3,1,2,4,5,5,6 };
        assert(findKthLargest(nums, sizeof(nums) / sizeof(nums[0]), 4) == 4);
    }

    {
        int nums[] = { 3 };
        assert(findKthLargest(nums, sizeof(nums) / sizeof(nums[0]), 1) == 3);
    }

    return 0;
}
