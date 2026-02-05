class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        if (n == 1) {
            return 0;
        }
        while (l <= r) {
            int mid = (l + r) / 2;
            int leftNum = mid - 1 >= 0 ? nums[mid - 1] : INT_MIN;
            int rightNum = mid + 1 < n ? nums[mid + 1] : INT_MIN;
            if (leftNum < nums[mid] && rightNum < nums[mid]) {
                return mid;
            }
            else if (leftNum <= nums[mid]) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }

        }
        return -1;
    }
};