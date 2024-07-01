/*
Given a binary tree check if it is broken or not.
If broken, remove faulty edge and convert it into valid binary tree.
Constraints :
Broken Binary Tree will have exactly one extra edge (N edges , N = number of vertices)
Follow Up :
How would you test ?
*/

/*
Solution Analysis :
Time Complexity : O(n) where n is number of nodes
Space Complexity : O(n)
*/

#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

struct TreeNode{
    TreeNode* left;
    TreeNode* right;

    TreeNode(){
        left = NULL;
        right = NULL;
    }
};

bool isBrokenBinaryTree(TreeNode* root){

    if(root == NULL){
        return false;
    }

    unordered_set<TreeNode*> visSet;
    queue<TreeNode*> bfsQ;

    visSet.insert(root);
    bfsQ.push(root);

    while(!bfsQ.empty()){
        TreeNode* cur = bfsQ.front();
        bfsQ.pop();

        if(visSet.find(cur->left) != visSet.end()){
            cur->left = NULL;
            return true;
        }
        if(visSet.find(cur->right) != visSet.end()){
            cur->right = NULL;
            return true;
        }

        if(cur->left){
            bfsQ.push(cur->left);
            visSet.insert(cur->left);
        }

        if(cur->right){
            bfsQ.push(cur->right);
            visSet.insert(cur->right);
        }
    }

    return false;
}

int main(){

    // Single Binary tree
    TreeNode* root1 = new TreeNode();
    assert(isBrokenBinaryTree(root1) == false);

    // Regular Binary Tree
    TreeNode* root2 = new TreeNode();
    root2->left = new TreeNode();
    root2->right = new TreeNode();
    root2->left->right = new TreeNode();
    root2->right->left = new TreeNode();
    root2->right->right = new TreeNode();
    assert(isBrokenBinaryTree(root2) == false);

    // Binary Tree with extra edge between siblings
    TreeNode* root3 = new TreeNode();
    root3->left = new TreeNode();
    root3->right = new TreeNode();
    root3->left->right = root3->right;
    assert(isBrokenBinaryTree(root3) == true);
    assert(isBrokenBinaryTree(root3) == false); // Verifying faulty edge is removed : Testing :D

    // Binary Tree with extra edge to ancestor
    TreeNode* root4 = new TreeNode();
    root4->left = new TreeNode();
    root4->right = new TreeNode();
    root4->left->left = new TreeNode();
    root4->left->left->left = root4;
    assert(isBrokenBinaryTree(root4) == true);
    assert(isBrokenBinaryTree(root4) == false); // Verifying faulty edge is removed : Testing :D

    // Binary Tree with child having two parents
    TreeNode* root5 = new TreeNode();
    root5->left = new TreeNode();
    root5->right = new TreeNode();
    root5->left->right = new TreeNode();
    root5->right->left = root5->left->right;
    assert(isBrokenBinaryTree(root5) == true);
    assert(isBrokenBinaryTree(root5) == false); // Verifying faulty edge is removed : Testing :D

    // Binary Tree with node having self-loop
    TreeNode* root6 = new TreeNode();
    root6->left = new TreeNode();
    root6->right = root6;
    assert(isBrokenBinaryTree(root6) == true);
    assert(isBrokenBinaryTree(root6) == false); // Verifying faulty edge is removed : Testing :D

    return 0;
}