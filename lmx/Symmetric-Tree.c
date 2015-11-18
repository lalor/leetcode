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

bool isSubTreeSymmetric(struct TreeNode* a, struct TreeNode* b) {
    if ( a == NULL && b == NULL) return TRUE;
    if (a == NULL || b == NULL) return FALSE;
    if ( a->val != b->val ) return FALSE;
    else return isSubTreeSymmetric(a->right, b->left) && (a->left, b->right);
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) return TRUE;

    if (root->left == NULL && root->right == NULL ) return TRUE;

    if (root->left == NULL || root->right == NULL ) return FALSE;

    if (root->left->val != root->right->val) return FALSE;
    else return isSubTreeSymmetric(root->left, root->right);
}

int main(int argc, char* argv[])
{

    //int a[] = {5, 4, 6, 8, 9, 1, 3, 2, 7};
    int a[] = {2, 1, 3};
    const int size = sizeof a / sizeof a[0];

    int distance = 0;
    int i;

    struct TreeNode*  root = NULL;

    for ( i = 0; i < size; i++)
        root = insert(root, a[i]);

    printf("%d\n", isBalanced(root));


    //    printf("\nthe depth of binary tree is : %d\n", depth(root));
    //    printf("\nthe depth of binary tree is : %d\n", maxdistance(root, &distance));
    //    printf("\nthe max distance of binary tree is : %d\n", distance);
    //

    return 0;
}
