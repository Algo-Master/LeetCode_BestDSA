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
    bool hb = true;
    int height(TreeNode* node) {

        if(node == nullptr) return 0;

        int hl = height(node->left), hr = height(node->right);
        if(abs(hl - hr) > 1) hb = false;
        
        return max(hl, hr) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        height(root);
        return hb;
    }
};