class Solution {
    // Order: Node, Weight
    vector<pair<int, int>> adj[1000];
    vector<bool> vis;
public:
    int prim() {
        // Order: Weight, Node
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        vis.resize(1000, false);

        int sum = 0;

        while(!pq.empty()) {
            int node = pq.top().second, wgt = pq.top().first;
            pq.pop();

            if(vis[node]) continue;
            vis[node] = 1;
            sum += wgt;

            for(auto &[child, w]: adj[node]) {
                if(!vis[child]) {
                    pq.push({w, child});
                }
            }
        }

        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();
        
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                adj[i].push_back({j, abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])});
                adj[j].push_back({i, abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])});
            }
        }

        return prim();
    }
};