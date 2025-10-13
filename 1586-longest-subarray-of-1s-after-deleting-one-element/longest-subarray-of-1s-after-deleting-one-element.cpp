class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, right = 0;
        int n = nums.size();
        int best = 0, zeroCount = 0;

        for (right =  0; right < n; right++) {
            if (nums[right] == 0) {
                zeroCount++;
            }

            while (zeroCount > 1) {
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }
            best = max(best, right - left);
        }

        return best;
    }
};