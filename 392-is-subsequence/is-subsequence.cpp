class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size(), n = t.size();
        int subFlag = 0, oriFlag = 0;
        while (subFlag < m || oriFlag < n) {
            while (oriFlag < n && s[subFlag] != t[oriFlag]) {
                oriFlag++;
            }
            if (oriFlag >= n) {
                break;
            }
            subFlag++;
            oriFlag++;
        }
        if (subFlag != m) {
            return false;
        }
        return true;
    }
};