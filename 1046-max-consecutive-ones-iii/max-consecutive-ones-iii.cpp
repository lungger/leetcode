class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int n = nums.size();
        int zeroCount = 0;
        int best = 0;

        for (r = 0; r < n; r++) {
            if (nums[r] == 0) {
                zeroCount++;
            }
            while (zeroCount > k) {
                if (nums[l] == 0) {
                    zeroCount--;
                }
                l++;
            }
            best = max(best, r - l + 1);
        }
        return best;
    }
};