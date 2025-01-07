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
    bool dfs(TreeNode* node_1, TreeNode* node_2) {

        if(node_1 == nullptr && node_2 == nullptr) return true;

        if(node_1 == nullptr || node_2 == nullptr) return false;

        if(node_1->val != node_2->val) return false;

        return (dfs(node_1->left, node_2->left) && dfs(node_1->right, node_2->right));
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        return dfs(p, q);
    }
};