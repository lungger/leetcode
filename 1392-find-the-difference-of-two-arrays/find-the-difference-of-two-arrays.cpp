class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> S1, S2;
        for (int x : nums1) S1.insert(x);
        for (int y : nums2) S2.insert(y);

        vector<int> A0, A1;

        // S1 \ S2
        for (int x : S1) {
            if (S2.find(x) == S2.end()) {
                A0.push_back(x);
            }
        }
        // S2 \ S1
        for (int y : S2) {
            if (S1.find(y) == S1.end()) {
                A1.push_back(y);
            }
        }
        return {A0, A1};
    }
};