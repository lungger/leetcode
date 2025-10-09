class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size(), n = t.size();
        int subFlag = 0, oriFlag = 0;
        while (subFlag < m && oriFlag < n) {
            if(s[subFlag] == t[oriFlag]) {
                subFlag++;
            }
            oriFlag++;
        }
        
        return subFlag == m;
    }
};