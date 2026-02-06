class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int ans = INT_MAX;
        sort(piles.begin(), piles.end());
        if (h == n) {
            return piles[n-1];
        }

        int l = 1, r = piles[n-1];

        while (l <= r) {
            long long temp = 0;
            int mid = l + (r - l) / 2;
            for (long long i : piles) {
                temp += (i + mid - 1) / mid;
            }
            
            if (temp <= (long long)h) {
                r = mid - 1;
                ans = mid;
            }
            else if (temp > (long long)h) {
                l = mid + 1;
            }

        }
        return ans;
    }
};