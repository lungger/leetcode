class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = (int)rooms.size();
        vector<char> vis(n, 0);
        queue<int> q;

        vis[0] = 1;
        q.push(0);
        int visitedCount = 1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : rooms[u]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                    visitedCount++;
                }
            }
        }

        return visitedCount == n;
    }
};