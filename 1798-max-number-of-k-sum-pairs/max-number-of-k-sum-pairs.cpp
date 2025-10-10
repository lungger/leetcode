class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int, int> myMap;
        int ans = 0;

        for (auto i : nums) {
            myMap[i]++;
        }
        
        for (auto it = myMap.begin(); it != myMap.end(); it++) {
            int a = it->first;
            int b = k - a;

            if (a == b) {
                ans += it->second / 2;
            }
            else {
                auto jt = myMap.find(b);
                if (jt != myMap.end()) {
                    int m = min(jt->second, it->second);
                    ans += m;
                    jt->second -= m;
                    it->second -= m;
                }
            }
        }
        return ans;
    }
};