class Solution{
public:
        int orangesRotting(vector<vector<int>>& grid) {
            int m = grid.size(), n = grid[0].size();
            queue<pair<int, int>> q;
            int freshCount = 0, minutes = 0;
            
            // Step 1: Initialize the queue with rotten oranges and count fresh oranges
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 2) {
                        q.push({i, j});
                    } else if (grid[i][j] == 1) {
                        freshCount++;
                    }
                }
            }
            
            // Directions for 4-adjacency (Up, Down, Left, Right)
            vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            
            // Step 2: Perform BFS
            while (!q.empty() && freshCount > 0) {
                int size = q.size();
                minutes++;
                for (int i = 0; i < size; i++) {
                    auto p = q.front();
                    q.pop();
                    
                    for (auto &dir : directions) {
                        int nx = p.first + dir.first;
                        int ny = p.second + dir.second;
                        
                        // Check for valid fresh orange
                        if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                            grid[nx][ny] = 2;
                            freshCount--;
                            q.push({nx, ny});
                        }
                    }
                }
            }            
        return freshCount == 0 ? minutes : -1;
    }
};
