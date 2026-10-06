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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(root == nullptr) return ans;
        queue<TreeNode*>q;

        q.push(root);
        while(!q.empty()){

            int size = q.size();

            vector<int>result;

            for(int i = 0 ;i<size;i++){
            TreeNode* level = q.front();
            result.push_back(level->val);
            q.pop();
            if(level->left){
                q.push(level->left);
            }
            if(level->right){
                q.push(level->right);
            }
            }
            ans.push_back(result);
        }
        return ans;
        
    }
};
