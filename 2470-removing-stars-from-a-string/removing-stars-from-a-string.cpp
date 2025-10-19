class Solution {
public:
    string removeStars(string s) {
        vector<char> ans;

        for (char c : s) {
            if (c == '*') {
                ans.pop_back();
            }
            else {
                ans.push_back(c);
            }
        }  
        return string(ans.begin(), ans.end());
    }
};