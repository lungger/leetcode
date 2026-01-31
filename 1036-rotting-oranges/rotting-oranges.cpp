class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int freshCount = 0;
        queue<pair<int,int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }
        if (!freshCount)
            return 0;

        int min = -1;
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [row, col] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int nextRow = row + dr[k], nextCol = col + dc[k];
                    if (nextRow < 0 || nextRow >= m || nextCol < 0 || nextCol >= n) continue;
                    if (grid[nextRow][nextCol] == 2 || grid[nextRow][nextCol] == 0) continue;

                    grid[nextRow][nextCol] = 2;
                    freshCount--;
                    q.push({nextRow, nextCol});
                }
            }
            min++;
        }
        if (!freshCount) {
            return min;
        }
        return -1;
    }
};