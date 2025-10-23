class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> rQueue;
        queue<int> dQueue;
        int n = senate.size();
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') {
                rQueue.push(i);
            }
            if (senate[i] == 'D') {
                dQueue.push(i);
            }
        }

        while (!rQueue.empty() && !dQueue.empty()) {
            int r = rQueue.front();
            int d = dQueue.front();
            rQueue.pop();
            dQueue.pop();
            if (r < d) {
                rQueue.push(r + n);
            }
            else {
                dQueue.push(d + n);
            }
        }

        return rQueue.empty() ? "Dire" : "Radiant";
    }
};