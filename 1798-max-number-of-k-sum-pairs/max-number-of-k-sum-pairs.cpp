class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> myMap;
        int ans = 0;

        for (auto i : nums) {
            int y = k - i;
            auto it = myMap.find(y);
            if (it != myMap.end() && it->second > 0) {
                ++ans;
                --(it->second);
            }
            else {
                ++myMap[i];
            }
        }
    
        return ans;
    }
};