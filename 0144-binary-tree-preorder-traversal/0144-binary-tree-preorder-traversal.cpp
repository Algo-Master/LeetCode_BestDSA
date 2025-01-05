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
    void preorder(TreeNode* root) {
        traversal.push_back(root->val);

        if(root->left != nullptr) preorder(root->left);
        if(root->right != nullptr) preorder(root->right);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {

        if(root != nullptr) preorder(root);
        return traversal;
    }
};