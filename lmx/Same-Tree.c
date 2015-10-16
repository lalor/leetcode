#include<stdlib.h>
#include <stdio.h>

#define MIN(a, b) ( a > b ? b : a)
#define MAX(a, b) ( a > b ? a : b)
#define bool int
#define TRUE 1
#define FALSE 0


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


//build
struct TreeNode*  insert(struct TreeNode*  root, int key)
{
    if (root == NULL)
    {
        root = (struct TreeNode*)malloc(sizeof(*root));
        root->left  = NULL;
        root->right = NULL;
        root->val = key;
    }
    else
    {
        if (root->val > key) { root->left = insert(root->left, key); }
        else { root->right = insert(root->right, key); }
    }
    return root;
}

int maxDepth(struct TreeNode* root, int *isBalanced) {
    int l, r;
    if (root == NULL) return 0;
    r = maxDepth(root->right, isBalanced);
    l = maxDepth(root->left, isBalanced);
    if ( r - l > 1 || l - r > 1 ) {
        *isBalanced = FALSE;
    }
    return MAX(r, l) + 1;
}


bool isBalanced(struct TreeNode* root) {
    int isBalanced = TRUE;
    maxDepth(root, &isBalanced);
    return isBalanced;
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL) {
        return TRUE;
    } else if ( p == NULL || q == NULL) {
        return FALSE;
    } else if ( p->val != q->val) {
        return FALSE;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main(int argc, char* argv[])
{

    int a[] = {5, 4, 6, 8, 9, 1, 3, 2, 7};
    int b[] = {5, 4, 6, 8, 9, 1, 3, 2, 7};

    const int asize = sizeof a / sizeof a[0];
    const int bsize = sizeof b / sizeof b[0];

    struct TreeNode*  aroot = NULL;
    struct TreeNode*  broot = NULL;

    int i;
    for ( i = 0; i < asize; i++)
    {
        aroot = insert(aroot, a[i]);
    }

    for ( i = 0; i < bsize; i++)
    {
        broot = insert(broot, b[i]);
    }

    printf("%d\n", isSameTree(aroot, broot));

}
