class Solution {
public:
    bool checkExit(int borderRow, int borderCol, vector<int>& pos) {
        return pos[0] == 0 || pos[0] == borderRow || pos[1] == 0 || pos[1] == borderCol;
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int borderRow = maze.size() - 1;
        int borderCol = maze[0].size() - 1;
        vector<vector<int>> visited(maze.size(), vector<int>(maze[0].size(), 0));
        queue<vector<int>> q;

        entrance.push_back(0);
        visited[entrance[0]][entrance[1]]++;
        q.push(entrance);

        while(!q.empty()) {
            vector<int> pos = q.front();
            q.pop();
            if (pos[0] > 0 && maze[pos[0]-1][pos[1]] != '+' && !visited[pos[0]-1][pos[1]]) {
                vector<int> temp = pos;
                temp[0]--;
                temp[2]++;
                visited[temp[0]][temp[1]]++;
                if (checkExit(borderRow, borderCol, temp)) {
                    return temp[2];
                }
                q.push(temp);
            }
            if (pos[0] < borderRow && maze[pos[0]+1][pos[1]] != '+' && !visited[pos[0]+1][pos[1]]) {
                vector<int> temp = pos;
                temp[0]++;
                temp[2]++;
                visited[temp[0]][temp[1]]++;
                if (checkExit(borderRow, borderCol, temp)) {
                    return temp[2];
                }
                q.push(temp);
            }
            if (pos[1] > 0 && maze[pos[0]][pos[1]-1] != '+' && !visited[pos[0]][pos[1]-1]) {
                vector<int> temp = pos;
                temp[1]--;
                temp[2]++;
                visited[temp[0]][temp[1]]++;
                if (checkExit(borderRow, borderCol, temp)) {
                    return temp[2];
                }
                q.push(temp);
            }
            if (pos[1] < borderCol && maze[pos[0]][pos[1]+1] != '+' && !visited[pos[0]][pos[1]+1]) {
                vector<int> temp = pos;
                temp[1]++;
                temp[2]++;
                visited[temp[0]][temp[1]]++;
                if (checkExit(borderRow, borderCol, temp)) {
                    return temp[2];
                }
                q.push(temp);
            }
        }
        return -1;
    }
};