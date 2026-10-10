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
    int findmaxSumPath(TreeNode* root, int& maxSum) {
        if (root == nullptr) return 0;

        int left = findmaxSumPath(root->left, maxSum);
        int right = findmaxSumPath(root->right, maxSum);

        maxSum = max(maxSum, root->val + max(0, left) + max(0, right));

        return root->val + max(0, max(left, right));
    }

    int maxPathSum(TreeNode* root) {
        if (root == nullptr) return 0;
        int maxSum = INT_MIN;
        findmaxSumPath(root, maxSum);
        return maxSum;
    }
};
