/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
   public:
    // Encodes a tree to a single string.

    void helper(TreeNode* root, string& serial) {
        if (root == nullptr) {
            serial += "#,";
            return ;
        }
        serial += to_string(root->val) + ',';
        helper(root->left, serial);
        helper(root->right, serial);
    }

    string serialize(TreeNode* root) {
        string serial;
        if (root == nullptr) return "";
        helper(root, serial);
        return serial;
    }

    TreeNode* decrypt(string& data, int& index) {
        if (index >= data.size()) return nullptr;

        string token;

        while (index < data.size() && data[index] != ',') {
            token += data[index++];
        }
        index++;
        if (token == "#") return nullptr;

        TreeNode* node = new TreeNode(stoi(token));
        node->left = decrypt(data, index);
        node->right = decrypt(data, index);
        return node;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") return nullptr;
        int index = 0;
        return decrypt(data, index);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));