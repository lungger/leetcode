class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int, int> myMap;
        int ans = 0;

        for (auto i : nums) {
            if (myMap.find(i) == myMap.end()) {
                myMap[i] = 0;
            }
            myMap[i]++;
        }
        
        for (auto it = myMap.begin(); it != myMap.end(); it++) {
            if (it->first == k - it->first) {
                ans += it->second / 2;
            }
            else {
                int r = k - it->first;
                if (myMap.find(r) != myMap.end()) {
                    int m = min(myMap[r], it->second);
                    ans += m;
                    myMap[r] -= m;
                    it->second -= m;
                }
            }
        }
        return ans;
    }
};