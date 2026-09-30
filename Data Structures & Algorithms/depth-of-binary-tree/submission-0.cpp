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

    int calHeight(TreeNode* root){
        if(root == nullptr) return 0;

        int leftCount = calHeight(root->left);

        int rightCount = calHeight(root->right);

        return 1 + max(leftCount, rightCount);
    }
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;

        return calHeight(root);

    }
};
