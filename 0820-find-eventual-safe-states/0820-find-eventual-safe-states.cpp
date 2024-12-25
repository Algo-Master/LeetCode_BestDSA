class Solution {
public:
    vector<int> toposort_bfs(vector<vector<int>>& rev_graph) {
        int n = rev_graph.size();
        vector<int> indegree(n, 0);
        vector<int> order;
        queue<int> q;

        for(int i = 0; i < n; i++) {
            for(auto &child: rev_graph[i]) {
                indegree[child]++;
            }
        }

        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
                order.push_back(i);
            }
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto &child: rev_graph[node]) {
                indegree[child]--;

                if(indegree[child] == 0) {
                    q.push(child);
                    order.push_back(child);
                }
            }
        }

        return order;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        vector<vector<int>> rev_graph(graph.size());
        for(int i = 0; i < graph.size(); i++) {
            for(auto &child: graph[i]) {
                rev_graph[child].push_back(i);
            }
        }

        vector<int> topo = toposort_bfs(rev_graph);

        sort(topo.begin(), topo.end());
        return topo;
    }
};