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
    int mx_sum = INT_MIN;

    int path_sum(TreeNode* node) {

        if(node == nullptr) return 0;

        int hl = path_sum(node->left), hr = path_sum(node->right);
        mx_sum = max(mx_sum, max(hl, 0) + max(hr, 0) + node-> val);

        return max(max(hl, hr), 0) + node-> val;
    }
public:
    int maxPathSum(TreeNode* root) {
        
        path_sum(root);
        return mx_sum;
    }
};