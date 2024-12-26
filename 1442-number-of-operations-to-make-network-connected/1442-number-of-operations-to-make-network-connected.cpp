class Solution {
    vector<int> adj[100000];
    int vis[100000];
public:
    void dfs(int node, int &cycs, int parent) {

        vis[node] = 1;

        for(auto &child: adj[node]) {
            if(!vis[child]) {
                dfs(child, cycs, node);
            } else if(child != parent) cycs++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        for(int i = 0; i < connections.size(); i++) {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }

        int c = 0, cycs = 0;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs(i, cycs, -1);
                c++;
            }
        }
        cycs = (cycs>>1);
        return (cycs >= c-1? c-1 : -1);
    }
};