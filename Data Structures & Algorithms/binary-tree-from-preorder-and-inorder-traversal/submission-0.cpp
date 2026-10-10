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

    unordered_map<int, int> inOrderMap;
    TreeNode* helpBuildTree(vector<int> & preorder, int &index, int start, int end){
        if(start>end) return nullptr;

        int num = preorder[index++];
        TreeNode* root = new TreeNode(num);

        int mid = inOrderMap[num];

        root->left = helpBuildTree(preorder, index, start , mid-1);
        root -> right = helpBuildTree(preorder, index, mid+1, end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        


        for(int i = 0 ; i<inorder.size();i++){
            inOrderMap[inorder[i]] = i;
        }
        int start = 0 ;
        int end = inorder.size()-1;
        int index = 0;
        return helpBuildTree(preorder, index, start, end);

    }
};