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
    int dia = 0;

    int height(TreeNode* node) {

        if(node == nullptr) return 0;
        int hl = height(node->left), hr = height(node->right);
        
        dia = max(dia, hl + hr);
        return max(hl, hr) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {

        height(root);
        return dia;
    }
};