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

        // if(root != nullptr) preorder(root);
        // return traversal;

        // Iterative way

        stack<TreeNode*> st;
        st.push(root);

        vector<int> ans;
        if(root == nullptr) return ans;

        while(!st.empty()) {

            TreeNode* node = st.top();
            st.pop();

            ans.push_back(node->val);

            if(node->right != nullptr) st.push(node->right);
            if(node->left != nullptr) st.push(node->left);
        }

        return ans;
    }
};