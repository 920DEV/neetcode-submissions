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

class Solution {
public:

    int  checkBalHeight(TreeNode * root , bool & check ) {
        if(root == nullptr) return 0;
        int left = checkBalHeight(root->left, check) ;
        int right = checkBalHeight(root -> right , check);
        if(left - right > 1 || right - left > 1 ){
            check = false;
        }
        return 1 + max(left , right);
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;

        bool check = true;
     checkBalHeight(root , check);

     return check;

    }
};
