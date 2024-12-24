class Solution {
public:
    bool fg = true;
    vector<int> adj[2000];

    void toposort_dfs(int node, stack<int>&st, vector<int> &col) {
        col[node] = 1;

        for(auto &child: adj[node]) {
            if(col[child] == 0) {
                toposort_dfs(child, st, col);
            }
            else if(col[child] == 1) fg = 0;
        }
        col[node] = 2;
        st.push(node);
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>col(2000, 0);
        int n = prerequisites.size();
        for(int i = 0; i < n; i++) {
            vector<int> order = prerequisites[i];
            adj[order[1]].push_back(order[0]);
        }
        stack<int> st;
        for(int i = 0; i < numCourses; i++) {
            if(col[i] == 0) {
                toposort_dfs(i, st, col);
            }
        }

        return fg;
    }
};