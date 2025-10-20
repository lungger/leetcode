class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for (auto i : asteroids) {
            if (i > 0) {
                ans.push_back(i);
            }
            else {
                while (ans.size() != 0 && ans.back() > 0 && ans.back() < i * -1) {
                    ans.pop_back();
                }
                if (ans.size() != 0 && ans.back() == i * -1) {
                    ans.pop_back();
                    continue;
                }
                if (ans.size() == 0 || ans.back() < 0) {
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};