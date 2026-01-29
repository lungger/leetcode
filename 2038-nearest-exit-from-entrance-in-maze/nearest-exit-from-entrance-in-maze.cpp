class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        int startRow = entrance[0], startCol = entrance[1];

        queue<pair<int,int>> q;
        q.push({startRow, startCol});
        maze[startRow][startCol] = '+'; // mark visited

        int steps = 0;
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
                    if (maze[nextRow][nextCol] == '+') continue; // wall or visited

                    // next cell is reachable, steps+1
                    if (nextRow == 0 || nextRow == m-1 || nextCol == 0 || nextCol == n-1) {
                        return steps + 1;
                    }

                    maze[nextRow][nextCol] = '+'; // mark visited
                    q.push({nextRow, nextCol});
                }
            }
            steps++;
        }
        return -1;
    }
};