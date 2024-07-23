#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

// https://leetcode.cn/problems/same-tree/?envType=study-plan-v2&envId=top-interview-150

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (!p && !q)
        return true;

    if (!p || !q)
        return false;

    if (p->val != q->val)
        return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main()
{
    {
        struct TreeNode p, q;
        p.val = 1;
        p.left = NULL;
        p.right = NULL;
        q.val = 1;
        q.left = NULL;
        q.right = NULL;
        assert(isSameTree(&p, &q) == true);
    }

    return 0;
}
