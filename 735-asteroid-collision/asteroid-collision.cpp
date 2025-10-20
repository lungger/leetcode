class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for (auto i : asteroids) {
            if (i > 0) {
                ans.push_back(i);
            }
            else {
                while (ans.size() != 0 && ans.back() > 0 && ans.back() < -i) {
                    ans.pop_back();
                }
                if (ans.size() == 0 || ans.back() < 0) {
                    ans.push_back(i);
                }
                if (ans.size() != 0 && ans.back() == -i) {
                    ans.pop_back();
                }
            }
        }
        return ans;
    }
};