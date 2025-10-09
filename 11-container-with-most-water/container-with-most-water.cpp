class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int best = 0;
        int h = 0;
        while (left < right) {
            h = min (height[left], height[right]);
            best = max(best, (h * (right - left)));
            if (height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }
        return best;
    }
};