#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <stdio.h>
#include <algorithm>
using namespace std;


#define MIN(a, b) ( a > b ? b : a)
#define MAX(a, b) ( a > b ? a : b)

typedef struct BinaryTree* BinNode;
struct BinaryTree
{
    int val;
    BinNode lchild;
    BinNode rchild;
};



//build
BinNode insert(BinNode root, int key)
{
    if (root == NULL)
    {
        root = new BinaryTree;
        root->lchild = root->rchild = NULL;
        root->val = key;
    }
    else
    {
        if (root->val > key) { root->lchild = insert(root->lchild, key); }
        else { root->rchild = insert(root->rchild, key); }
    }
    return root;
}



//traverse
void traverseByLevel( BinNode root )
{
    if (root == NULL) return;

    queue<BinNode> q;
    q.push(root);
    int preSize = 1, curSize = 0;
    while ( !q.empty() )
    {
        BinNode t = q.front(); q.pop();
        cout << t->val << "\t";
        if (t->lchild){ q.push(t->lchild); curSize++; }
        if (t->rchild){ q.push(t->rchild); curSize++; }
        if ( --preSize == 0 ) { cout << "\n"; preSize = curSize; curSize = 0; }
    }
}



//1. GetNodeNum
int GetNodeNum(BinNode root)
{
    int l, r;
    if (root == NULL) return 0;
    l = GetNodeNum(root->lchild);
    r = GetNodeNum(root->rchild);
    return l + r + 1;
}



//2. depth
int depth( BinNode root)
{
    int l, r;
    if (root == NULL) return 0;
    r = depth(root->rchild);
    l = depth(root->lchild);
    return MAX(r, l) + 1;
}



//3. traverse
void preOrder( BinNode root )
{
    stack<BinNode> s;
    BinNode p = root;
    while ( p != NULL || !s.empty())
    {
        while ( p != NULL )
        {
            s.push(p);
            cout << p->val << "\t";
            p = p->lchild;
        }
        if (!s.empty())
        {
            p = s.top();
            s.pop();
            p = p->rchild;
        }
    }
    cout << endl;
}
void InOrder( BinNode root )
{
    stack<BinNode> s;
    BinNode p = root;
    while ( p != NULL || !s.empty())
    {
        while ( p != NULL )
        {
            s.push(p);
            p = p->lchild;
        }
        if (!s.empty())
        {
            p = s.top();
            s.pop();
            cout << p->val << "\t";
            p = p->rchild;
        }
    }
    cout << endl;
}
void PostOrder( BinNode root )
{
    stack<BinNode> s;
    s.push(root);
    BinNode pre = NULL;
    BinNode cur = NULL;
    while (!s.empty())
    {
        cur = s.top();
        if ( (cur->lchild == NULL && cur->rchild == NULL) ||
                (pre != NULL && (pre == cur->lchild || pre == cur->rchild)) )
        {
            cout << cur->val << "\t";
            s.pop();
            pre = cur;
        }
        else
        {
            if( cur->rchild != NULL )s.push(cur->rchild);
            if( cur->lchild != NULL )s.push(cur->lchild);
        }
    }
    cout << endl;
}




//7. GetNodeNumKthLevel
int GetNodeNumKthLevel( BinNode root, int k)
{
    if (root == NULL || k < 0) return 0;
    if ( k == 0 ) return 1;
    return GetNodeNumKthLevel(root->lchild, k-1) + GetNodeNumKthLevel(root->rchild, k-1);
}



//8. same structure
int Structurecmp(BinNode root1, BinNode root2)
{
    if( root1 == NULL &&  root2 == NULL) return 1;
    if (root1 == NULL || root2 == NULL) return 0;
    int l = Structurecmp(root1->lchild, root2->lchild);
    int r = Structurecmp(root1->rchild, root2->rchild);
    return (l && r);
}



//9. is AVL
int IsAVL(BinNode root, int *height)
{
    if (root == NULL) { *height = 0; return 1; }

    int heightLeft = 0, heightRight = 0;
    int resultLeft = 0, resultRight = 0;

    resultLeft = IsAVL(root->lchild, &heightLeft);
    resultRight = IsAVL(root->rchild, &heightRight);

    *height = MAX(heightLeft, heightRight)+1;
    if ( resultLeft && resultRight && abs(heightLeft - heightRight) <= 1) return 1;
    else return 0;
}


//10. mirror
BinNode Mirror(BinNode root)
{
    if (root == NULL) return root;

    BinNode temp = root->lchild;
    root->lchild = root->rchild;
    root->rchild = temp;

    root->lchild = Mirror(root->lchild);
    root->rchild = Mirror(root->rchild);
    return root;
}



//11. common ancestor

// 12. max distance
int maxdistance(BinNode root, int *max)
{
    int l, r;
    int d;
    if (root == NULL) return 0;
    r = depth(root->rchild);
    l = depth(root->lchild);
    d = MAX(r, l) + 1;
    *max = MAX(*max, r + l);
    return d;
}




//13. sumToVal
void sumToVal(BinNode root, int val)
{

}

int main(int argc, char* argv[])
{

    int a[] = {5, 4, 6, 8, 9, 1, 3, 2, 7};
    int distance = 0;
    const int size = sizeof a / sizeof a[0];
    int i;

    BinNode root = NULL;

    for ( i = 0; i < size; i++)
        root = insert(root, a[i]);


    //    traverse(root);
    printf("the num of node is : %d\n", GetNodeNum(root));
    traverseByLevel(root);

    preOrder(root);

    root = Mirror(root);
    preOrder(root);
    InOrder(root);

    //    printf("\nthe depth of binary tree is : %d\n", depth(root));
    //    printf("\nthe depth of binary tree is : %d\n", maxdistance(root, &distance));
    //    printf("\nthe max distance of binary tree is : %d\n", distance);
    //

    return 0;
}
