class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        unordered_map<int, int> last;
        vector<int> ans(n, 1);
        set<int> dryDays;

        for (int i = 0; i < n; i++) {
            if (rains[i] != 0) {
                ans[i] = -1;
                int lake = rains[i];
                if (last.count(lake))  {
                    auto it = dryDays.upper_bound(last[lake]);
                    if (it == dryDays.end())
                        return {};
                    ans[*it] = lake;
                    dryDays.erase(it);
                }
                last[lake] = i;
            }
            else {
                dryDays.insert(i);
            }
        }
        return ans;
    }
};