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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> zigzaglevel;
        if(root == nullptr) return zigzaglevel;

        queue<TreeNode*> q;
        q.push(root);

        int flag = 0;

        while(!q.empty()) {
            int sz = q.size();
            vector<int>level;

            for(int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                level.push_back(node->val);
                q.pop();

                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
            }
            if(flag) {
                reverse(level.begin(), level.end());
                zigzaglevel.push_back(level);
            }
            else zigzaglevel.push_back(level);

            flag = (flag^1);
        }

        return zigzaglevel;
    }
};