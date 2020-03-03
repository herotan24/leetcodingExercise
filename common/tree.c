
#define MAXSIZE 100
 
/** 二叉树数据结构定义 **/
typedef struct TreeNode {
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode,*PtreeNode;


/*
 * 二叉树的建立--按照先序方式建立--插入
 */
void CreateBiTree(PtreeNode *T)
{
    char val;
    scanf("%c",&val);
 
    if(val == '#')
        *T = NULL;  //null表示为空枝
 
    else
    {
        *T = (PtreeNode)malloc(sizeof(TreeNode));
        (*T)->data = val;
        CreateBiTree(&(*T)->left);
        CreateBiTree(&(*T)->right);
    }
}

/**先序遍历  根左右**/
void PreOrderTravel(PtreeNode T)
{
    if(T==NULL)
        return;
    printf("%c ",T->data);
    PreOrderTravel(T->left);
    PreOrderTravel(T->right);
}
 
/**中序遍历 左根右**/
void InOrderTravel(PtreeNode T)
{
    if(T==NULL)
        return;
    InOrderTravel(T->left);
    printf("%c ",T->data);
    InOrderTravel(T->right);
}
 
/**后序遍历 左右根**/
void TailOrderTravel(PtreeNode T)
{
    if(T==NULL)
        return;
    TailOrderTravel(T->left);
    TailOrderTravel(T->right);
    printf("%c ",T->data);
}
