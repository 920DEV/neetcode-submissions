/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool validateBst(TreeNode* root, long long maxValue, long long  minValue) {
        if (root == nullptr)
            return true;

        if (root->val <= minValue || root->val >= maxValue)
            return false;

        bool left = validateBst(root->left, root->val, minValue);
        if (!left)
            return false;
        bool right = validateBst(root->right, maxValue, root->val);
        if (!right)
            return false;

        return true;
    }

    bool isValidBST(TreeNode* root) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr))
            return true;

        return validateBst(root, LONG_MAX, LONG_MIN);
    }
};