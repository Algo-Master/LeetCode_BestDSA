class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    int bfs(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), tim = 0;
        queue<pair<int, int>> q;
        vector<vector<int>> distance(m, vector<int>(n, -1));

        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2) {
                    q.push({i, j});
                    distance[i][j] = 0;
                }
            }
        }

        while(!q.empty()) {
            pair<int, int> node = q.front();
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nx = node.first + dx[i], ny = node.second + dy[i];

                if(nx<0 || nx>=m || ny<0 || ny>=n) continue;

                if(grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    distance[nx][ny] = distance[node.first][node.second] + 1;
                    q.push({nx, ny});
                }
                tim = max(tim, distance[nx][ny]);
            }
        }
        return tim;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        
        int tm = bfs(grid);
        int m = grid.size(), n = grid[0].size();

        bool fg = 1;
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) fg = 0;
            }
        }

        return (fg? tm : -1);
    }
};