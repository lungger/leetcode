class Solution {
public:
    void backTracking(vector<vector<int>>& ans, vector<int>& combine, int start, int combineTotal, int k, int n) {
        if (k == 0) {
            if (combineTotal == n) {
                ans.push_back(combine);
            }
            return;
        }
        if (combineTotal > n) {
            return;
        }

        for (int i = start; i < 10; i++) {
            combine.push_back(i);
            combineTotal += i;
            backTracking(ans, combine, i+1, combineTotal, k-1, n);
            combine.pop_back();
            combineTotal -= i;
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> combine;
        int combineTotal = 0;

        backTracking(ans, combine, 1, combineTotal, k, n);

        return ans;
    }
};