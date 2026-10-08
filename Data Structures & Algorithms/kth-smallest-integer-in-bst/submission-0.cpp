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
    int inOrderTraverse(TreeNode* root, int k , int&count){
        if(root == nullptr) return -1;

       int left =  inOrderTraverse(root->left, k, count);
       if(left != -1 ) return left;
       count++;
       if(count == k ) return root->val;

    int right =  inOrderTraverse(root->right, k,count );
    if(right != -1) return right;

        return -1;
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root == nullptr) return -1;

        int count = 0;
        
        return inOrderTraverse(root, k , count);
    }
};