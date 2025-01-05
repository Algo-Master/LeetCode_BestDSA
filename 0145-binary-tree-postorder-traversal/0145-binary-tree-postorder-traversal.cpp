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
    void postorder(TreeNode* root) {
        if(root->left != nullptr) postorder(root->left);
        if(root->right != nullptr) postorder(root->right);

        traversal.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root != nullptr) postorder(root);
        return traversal;
    }
};