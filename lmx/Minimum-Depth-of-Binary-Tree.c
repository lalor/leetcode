#include<stdlib.h>
#include <stdio.h>
#include <limits.h>

#define MIN(a, b) ( a > b ? b : a)
#define MAX(a, b) ( a > b ? a : b)


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



int maxDepth(struct TreeNode* root) {
    int l, r;
    if (root == NULL) return 0;
    r = maxDepth(root->right);
    l = maxDepth(root->left);
    return MAX(r, l) + 1;
}

int minDepth(struct TreeNode* root) {
    int l = INT_MAX, r = INT_MAX;

    if (root == NULL) return 0;

    if (root->left == NULL && root->right == NULL) return 1;

    if (root->left != NULL) {
        l = minDepth(root->left) + 1;
    }
    if (root->right != NULL) {
        r = minDepth(root->right) + 1;
    }
    return MIN(r, l);
}

int main(int argc, char* argv[])
{

    //int a[] = {5, 4, 6, 8, 9, 1, 3, 2, 7};
    int a[] = {1, 2};
    const int size = sizeof a / sizeof a[0];

    int distance = 0;
    int i;

    struct TreeNode*  root = NULL;

    for ( i = 0; i < size; i++)
        root = insert(root, a[i]);

    printf("%d\n", minDepth(root));


    //    printf("\nthe depth of binary tree is : %d\n", depth(root));
    //    printf("\nthe depth of binary tree is : %d\n", maxdistance(root, &distance));
    //    printf("\nthe max distance of binary tree is : %d\n", distance);
    //

    return 0;
}
