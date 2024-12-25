class Solution {
public:
    vector<int> parent, sz, edge;
    int findParent(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }
    void unionBySize(int u, int v) {

        int ulp_u = findParent(u), ulp_v = findParent(v);

        if(ulp_u == ulp_v) {
            edge.push_back(u);
            edge.push_back(v);
            return;
        }

        if(sz[ulp_u] > sz[ulp_v]) {
            parent[ulp_v] = ulp_u;
            sz[ulp_u] += sz[ulp_v];
        } else {
            parent[ulp_u] = ulp_v;
            sz[ulp_v] += sz[ulp_u];
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = 0;
        for(auto &connect: edges) {
            n = max(n, connect[0]);
            n = max(n, connect[1]);
        }

        parent.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
        sz.resize(n+1, 1);

        for(auto &connect: edges) {
            unionBySize(connect[0], connect[1]);
        }

        return edge;
    }
};