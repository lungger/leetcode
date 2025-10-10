class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());  // O(n log n)

        int l = 0, r = (int)nums.size() - 1;
        int ans = 0;

        while (l < r) {
            int sum = nums[l] + nums[r];
            if (sum == k) {
                ++ans;
                ++l; --r;
            } else if (sum < k) {
                ++l;  // 和太小，左指針右移增加和
            } else {
                --r;  // 和太大，右指針左移減少和
            }
        }
    
        return ans;
    }
};