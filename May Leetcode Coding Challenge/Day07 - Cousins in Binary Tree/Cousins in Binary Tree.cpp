/*
 
Problem Statement:
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.
Two nodes of a binary tree are cousins if they have the same depth, but have different parents.
We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.
Return true if and only if the nodes corresponding to the values x and y are cousins.

Example:

Input: root = [1,2,3,4], x = 4, y = 3
        1
       / \
      2   3
    /
   4 
Output: false

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Solution

class Solution {
public:
    
    pair<TreeNode*, int > a;
    void findNode(TreeNode* root, int find, int depth){
        if(root->left && root->left->val == find){
            a = make_pair(root, depth+1);
            return;
        }else if(root->right && root->right->val == find){
            a = make_pair(root, depth+1);
            return;
        }else{
            if(root->left){
                cout<<"a\n";
                findNode(root->left, find, depth+1);
            }
            if(root->right){
                cout<<"b\n";
                findNode(root->right, find, depth+1);
            }
        }
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        pair<TreeNode*, int> one; 
        pair<TreeNode*, int> two;
        if(x == root->val){
            one = make_pair(root, 0);
        }else{
            findNode(root, x, 0); 
            one = a;
        }
        if(y == root->val){
            two = make_pair(root, 0);
        }else{
            findNode(root, y, 0);
            two = a;
        }
        cout<<one.first->val<<" ... "<<two.first->val;
        return one.first->val != two.first->val && one.second == two.second;
    }
};