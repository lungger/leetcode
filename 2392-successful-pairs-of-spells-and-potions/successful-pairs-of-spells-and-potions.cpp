class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> ans(spells.size(), 0); 
        for (int i = 0; i < spells.size(); i++) {
            long long s = spells[i];
            int l = 0;
            int r = potions.size() - 1;
            int mid;
            while (l <= r) {
                mid = (l + r) / 2;
                long long product = (long long)s * (long long)potions[mid];
                if (product >= success) {
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }

            }
            ans[i] = n - l;
        }
        return ans;
    }
};