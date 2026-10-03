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
    bool checkSubTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr)
            return true;
        if (p == nullptr && q != nullptr)
            return false;
        if (p != nullptr && q == nullptr)
            return false;
        if (p->val != q->val)
            return false;

        bool left = checkSubTree(p->left, q->left);
        if (!left)
            return false;

        bool right = checkSubTree(p->right, q->right);
        if (!right)
            return false;

        return true;
    }


    bool iterateTree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr && subRoot == nullptr)
            return true;
        if (root == nullptr && subRoot != nullptr)
            return false;
        if (subRoot == nullptr)
            return true;

        if (root->val == subRoot->val) {
            if(checkSubTree(root, subRoot)) return true;
        }

        bool left = iterateTree(root->left, subRoot);

        if(left) return true;
        bool right = iterateTree(root->right, subRoot);
        if(right ) return true;
        return false;
    }


    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr && subRoot == nullptr)
            return true;
        if (root == nullptr && subRoot != nullptr)
            return false;
        if (subRoot == nullptr)
            return true;

        return iterateTree(root, subRoot);
    }
};
