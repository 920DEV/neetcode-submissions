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

    int calculateDiameter(TreeNode * root, int & diam){
        if(root == nullptr ) return 0;

        int left = calculateDiameter(root->left, diam);
        int right = calculateDiameter(root->right, diam);

        diam = max(diam, left + right);

        return 1+ max(left , right);
    }
int diameterOfBinaryTree(TreeNode* root) {
    int diam = 0;

    calculateDiameter(root, diam);

    return diam;
}
};
