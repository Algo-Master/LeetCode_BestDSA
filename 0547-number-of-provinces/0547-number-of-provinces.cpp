class Solution {
    vector<int> adj[200];
    int vis[200];
public:
    void bfs(int source) {
        queue<int> q;
        q.push(source);

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            for(auto &child: adj[node]) {
                if(!vis[child]) {
                    vis[child] = 1;
                    q.push(child);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(isConnected[i][j]) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }


        int c = 0;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                bfs(i);
                c++;
            }
        }
        return c;
    }
};