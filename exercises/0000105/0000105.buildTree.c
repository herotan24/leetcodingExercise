#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define MAXNUM 10000
struct TreeNode g_buf[MAXNUM] = {0};
int g_element_num = 0;
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize)
{
    struct TreeNode *parent = NULL;
    int *preorderTmp = NULL;
    int *inorderTmp = NULL;
    int rootIdxInInorde;
    int childNum;

    if (!preorderSize) {
        return NULL;
    }

    /* 从先序中确认父节点，并创建 */
    parent = &g_buf[g_element_num++];
    parent->val = preorder[0];

    /* 从中序中分割左树与右树 */
    for (rootIdxInInorde = 0; rootIdxInInorde < inorderSize; rootIdxInInorde++) {
        if (parent->val == inorder[rootIdxInInorde]) {
            break;
        }
    }

    /* 左树处理 */
    childNum = rootIdxInInorde - 0;
    if (childNum > 0) {
        preorderTmp = &preorder[0 + 1];
        inorderTmp = &inorder[0];

        parent->left = buildTree(preorderTmp, childNum, inorderTmp, childNum);
    }

    /* 右树处理 */
    childNum = (inorderSize - 1) - rootIdxInInorde;
    if (childNum > 0) {
        preorderTmp = &preorder[preorderSize - childNum];

        inorderTmp = &inorder[rootIdxInInorde + 1];
        parent->right = buildTree(preorderTmp, childNum, inorderTmp, childNum);
    }

    return parent;
}

/* 先序遍历 */
void PreOrderTravel(struct TreeNode *p)
{
    if (!p) {
        return;
    }

    printf("%d ",p->val);

    if (p->left) {
        PreOrderTravel(p->left);
    }

    if (p->right) {
        PreOrderTravel(p->right);
    }

    return;
}

int main(void) {
    if (0)
    {
        struct TreeNode *tree = NULL;
        
        tree = buildTree(NULL, 0, NULL, 0);

        printf("\n start \n");
        PreOrderTravel(tree);
        printf("\n end \n");
    }

    {
        int preorder[] = {3,9,20,15,7};
        int inorder[] = {9,3,15,20,7};

        struct TreeNode *tree = NULL;
        
        tree = buildTree(preorder, sizeof(preorder) / sizeof(preorder[0]), inorder, sizeof(inorder) / sizeof(inorder[0]));

        printf("\n start \n");
        PreOrderTravel(tree);
        printf("\n end \n");
    }

    return 0;
}