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
        // if(root != nullptr) inorder(root);
        // return traversal;

        // Iterative way which i figured out

        stack<TreeNode*> st;
        st.push(root);

        if(root == nullptr) return traversal;
        unordered_map<TreeNode*, bool> m;

        while(!st.empty()) {

            TreeNode* node = st.top();

            if(node->left != nullptr && !m[node->left]) {
                st.push(node->left);
                continue;
            }

            traversal.push_back(node->val);
            st.pop();
            m[node] = true;

            if(node->right != nullptr) {
                st.push(node->right);
            }
        }

        return traversal;
    }
};