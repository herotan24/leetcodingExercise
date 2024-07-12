#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <glib.h>
#include <glib/glist.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    int **ret;
    int *array;

    ret = NULL;
    *returnSize = 0;
    *returnColumnSizes = NULL;

    qsort(nums, numsSize, sizeof(int), cmp);

    for (int i = 0; i <= (numsSize - 3); i++) {
        if (i == 0 || nums[i] != nums[i - 1]) {

            for (int j = (i + 1); j <= (numsSize - 2); j++) {
                if (j == (i + 1) || nums[j] != nums[j - 1]) {

                    for (int k = (j + 1); k <=(numsSize - 1); k++) {
                        if (k == (j + 1) || nums[k] != nums[k - 1]) {

                            int sum = nums[i] + nums[j] + nums[k];
                            if (sum  == 0) {
                                array = malloc(3 * sizeof(int));
                                array[0] = nums[i];
                                array[1] = nums[j];
                                array[2] = nums[k];
                                (*returnSize)++;
                                ret = realloc(ret, (*returnSize) * sizeof(int *));
                                ret[(*returnSize) - 1] = array;
                                (*returnColumnSizes) = realloc((*returnColumnSizes), (*returnSize) * sizeof(int));
                                (*returnColumnSizes)[(*returnSize) - 1] = 3;
                            }

                            if (sum > 0) {
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    return ret;
};

int main() {

    {
        int nums[] = {-1, 0, 1, 2, -1, -4};
        int numsSize = 6;
        int returnSize = 0;
        int *returnColumnSizes = NULL;
        int **ret = NULL;
        int ret_ans[][3] = {{-1, -1, 2}, {-1, 0, 1}};
        int returnSize_ans = 2;
        int returnColumnSizes_ans[] = {3, 3};

        ret = threeSum(nums, numsSize, &returnSize, &returnColumnSizes);
        assert(!memcmp(ret[0], ret_ans[0], sizeof(ret_ans[0])));
        assert(!memcmp(ret[1], ret_ans[1], sizeof(ret_ans[1])));
        assert(returnSize == returnSize_ans);
        assert(!memcmp(returnColumnSizes, returnColumnSizes_ans, sizeof(returnColumnSizes_ans)));
    }

    {
        int nums[] = {0, 1, 1};
        int numsSize = 3;
        int returnSize = 0;
        int *returnColumnSizes = NULL;
        int **ret = NULL;
        int ret_ans[][3] = {};
        int returnSize_ans = 0;
        //int returnColumnSizes_ans[] = NULL;

        ret = threeSum(nums, numsSize, &returnSize, &returnColumnSizes);
        (void)ret;
        (void)ret_ans;
        (void)returnSize_ans;
        assert(returnSize == returnSize_ans);
    }

    {
        int nums[] = {0, 0, 0};
        int numsSize = 3;
        int returnSize = 0;
        int *returnColumnSizes = NULL;
        int **ret = NULL;
        int ret_ans[][3] = {{0, 0, 0}};
        int returnSize_ans = 1;
        int returnColumnSizes_ans[] = { 3 };

        ret = threeSum(nums, numsSize, &returnSize, &returnColumnSizes);
        assert(!memcmp(ret[0], ret_ans[0], sizeof(ret_ans[0])));
        assert(returnSize == returnSize_ans);
        assert(!memcmp(returnColumnSizes, returnColumnSizes_ans, sizeof(returnColumnSizes_ans)));
    }

    return 0;
}

/*

    l1  l2 l3
    {-4 -1, -1, 0, 1, 2};
 */
