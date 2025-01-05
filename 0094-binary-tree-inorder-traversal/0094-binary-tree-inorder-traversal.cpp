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
private:
    vector<int> traversal;
    void inorder(TreeNode* root) {
        if(root->left != nullptr) inorder(root->left);
        traversal.push_back(root->val);
        if(root->right != nullptr) inorder(root->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root != nullptr) inorder(root);
        return traversal;
    }
};