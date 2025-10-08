class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0, right = 0;
        while (left <= right && right < nums.size() && left < nums.size()) {
            while (left < nums.size() && nums[left] != 0) {
                left++;
            }
            right = left;
            while (right < nums.size() && nums[right] == 0) {
                right++;
            }
            if (left < right && right < nums.size() && left < nums.size()) {
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
            }
        }
    }
};