class Solution {
public:
    void backTracking(string digits, string mapping[], vector<string>& ans, string combine, int index)  {
        if (index == digits.size()) {
            ans.push_back(combine);
            return;
        }

        for (auto c : mapping[digits[index] - '0']) {
            combine.push_back(c);
            backTracking(digits, mapping, ans, combine, index+1);
            combine.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        backTracking(digits, mapping, ans, "", 0);
        return ans;
    }
};