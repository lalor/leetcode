#include <iostream>
#include <vector>
#include <queue>


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        vector< vector<int> > levelOrder(TreeNode* root) {

            vector< vector<int> > r;
            if (root == NULL) {
                return r;
            }

            queue<TreeNode*> q;

            q.push(root);
            int levelCount = 1;

            vector<int> v;
            while( !q.empty()) {
                TreeNode* t = q.front(); q.pop();
                v.push_back(t->val);

                if (t->left != NULL) { q.push(t->left); }
                if (t->right != NULL) { q.push(t->right);}

                if (--levelCount == 0) {
                    r.push_back(v);
                    v.clear();
                    levelCount = q.size();
                }
            }
            return reverse(
        }
};


TreeNode* createTree(int a[], int n)
{
    if (n<=0) return NULL;

    TreeNode **tree = new TreeNode*[n];

    for(int i=0; i<n; i++) {
        if (a[i]==0 ){
            tree[i] = NULL;
            continue;
        }
        tree[i] = new TreeNode(a[i]);
    }
    int pos=1;
    for(int i=0; i<n && pos<n; i++) {
        if (tree[i]){
            tree[i]->left = tree[pos++];
            if (pos<n){
                tree[i]->right = tree[pos++];
            }
        }
    }
    return tree[0];
}

int printMatrix(vector< vector<int> > &vv)
{
    for(int i=0; i<vv.size(); i++) {
        cout << "[";
        for(int j=0; j<vv[i].size(); j++) {
            cout << " " << vv[i][j];
        }
        cout << "]" << endl;;
    }
}



void printTree(TreeNode *root)
{
    if (root == NULL){
        printf("# ");
        return;
    }
    printf("%d ", root->val );

    printTree(root->left);
    printTree(root->right);
}

void printTree_level_order(TreeNode *root)
{
    if (root == NULL) return;
    printf("%d\n", root->val);
    printTree_level_order(root->left);
    printTree_level_order(root->right);
}

int main()
{
    TreeNode *p;
    vector< vector<int> > vv;

    Solution s;
    int a[] = {1,2,3,4,5,0,0};
    p = createTree(a, sizeof(a)/sizeof(int));
    printTree_level_order(p);
    vv = s.levelOrder(p);
    printMatrix(vv);
    cout << endl;

//    int b[] = {1,0,2};
//    p = createTree(b, sizeof(b)/sizeof(int));
//    printTree_level_order(p);
//    vv = levelOrder(p);
//    printMatrix(vv);
//    cout << endl;
//
//    int c[] = {1,2,0,3,0,4,0,5};
//    p = createTree(c, sizeof(c)/sizeof(int));
//    printTree_level_order(p);
//    vv = levelOrder(p);
//    printMatrix(vv);
//    cout << endl;
//
//    int d[] = {1,2,3,4,0,0,5};
//    p = createTree(d, sizeof(d)/sizeof(int));
//    printTree_level_order(p);
//    vv = levelOrder(p);
//    printMatrix(vv);
//    cout << endl;
//    return 0;
}
