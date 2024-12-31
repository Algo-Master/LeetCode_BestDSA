class Solution {
    // Union by Size
    // Kruskal's Algorithm
    class DisjointSet {
    private:
        vector<int> parent, sz;

    public:
        DisjointSet(int n) {
            parent.resize(n + 1);
            sz.resize(n + 1, 1);
            for (int i = 1; i <= n; ++i) {
                parent[i] = i;
            }
        }

        int findParent(int node) {
            if (node == parent[node]) {
                return node;
            }
            // Path compression (crucial for efficiency)
            return parent[node] = findParent(parent[node]);
        }

        bool unionBySize(int u, int v) {

            int ulp_u = findParent(u);
            int ulp_v = findParent(v);

            if (ulp_u == ulp_v) {
                return false;
            }

            if (sz[ulp_u] > sz[ulp_v]) {
                parent[ulp_v] = ulp_u;
                sz[ulp_u] += sz[ulp_v];
            } else {
                parent[ulp_u] = ulp_v;
                sz[ulp_v] += sz[ulp_u];
            }
            return true;
        }
    };

    int kruskal(vector<vector<int>>& points) {

        int n = points.size();
        vector<pair<int, pair<int, int>>> edges;

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int wgt = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({wgt, {i, j}});
            }
        }

        sort(edges.begin(), edges.end());

        int sum = 0;
        DisjointSet ds(1000);

        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i].second.first;
            int v = edges[i].second.second;

            if(ds.unionBySize(u, v)) sum += edges[i].first;
        }

        return sum;
    }

    // Prim's Algorithm
    // Order: Node, Weight
    vector<pair<int, int>> adj[1000];
    vector<bool> vis;

public:
    int prim() {
        // Order: Weight, Node
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, 0});
        vis.resize(1000, false);

        int sum = 0;

        while (!pq.empty()) {
            int node = pq.top().second, wgt = pq.top().first;
            pq.pop();

            if (vis[node])
                continue;
            vis[node] = 1;
            sum += wgt;

            for (auto& [child, w] : adj[node]) {
                if (!vis[child]) {
                    pq.push({w, child});
                }
            }
        }

        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {

        return kruskal(points);

        int n = points.size();

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                adj[i].push_back({j, abs(points[i][0] - points[j][0]) +
                                         abs(points[i][1] - points[j][1])});
                adj[j].push_back({i, abs(points[i][0] - points[j][0]) +
                                         abs(points[i][1] - points[j][1])});
            }
        }

        return prim();
    }
};