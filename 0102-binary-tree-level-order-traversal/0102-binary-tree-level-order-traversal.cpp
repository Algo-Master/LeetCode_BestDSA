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

        vector<vector<int>> all_levels;
        if(root == nullptr) return all_levels;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int sz = q.size();
            vector<int> level;

            for(int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                level.push_back(node->val);

                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
                q.pop();
            }
            all_levels.push_back(level);
        }

        return all_levels;
    }
};