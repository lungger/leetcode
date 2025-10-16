class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> occurrences;
        unordered_set<int> occset;

        for (auto x : arr) ++occurrences[x];

        for (auto& [a, count] : occurrences) {
            if (occset.find(count) == occset.end()) {
                occset.insert(count);
            }
            else {
                return false;
            }
        }

        return true;
    }
};