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
  TreeNode* lowestCommonAncestor(TreeNode* root,
                               TreeNode* p,
                               TreeNode* q) {

    // Base case
    if (root == nullptr)
        return nullptr;

    // We found p or q
    if (root == p || root == q)
        return root;

    // Search both sides
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    // One target found on each side
    if (left != nullptr && right != nullptr)
        return root;

    // Only one side found something
    if (left != nullptr)
        return left;

    return right;
}
};
