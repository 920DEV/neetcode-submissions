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

    void countGoodNodes(TreeNode*root, int value, int &count,int maxValue){
        if(root == nullptr) return ;
        maxValue = max(maxValue , root->val);
        if(root->val >= maxValue && root->val >= value) count++ ;

        countGoodNodes(root->left, value, count, maxValue);
       countGoodNodes(root->right, value, count, maxValue);
    }
    int goodNodes(TreeNode* root) {
        if(root == nullptr ) return 0;
        int count = 0;
        int value = root->val;
        countGoodNodes(root, value,count,value);

        return count;
    }
};