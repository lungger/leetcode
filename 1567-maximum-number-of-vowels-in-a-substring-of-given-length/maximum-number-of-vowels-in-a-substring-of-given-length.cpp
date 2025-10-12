class Solution {
public:
    bool isVowel (char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxVowels(string s, int k) {
        int ans = 0, count = 0;
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) {
                ans++;
            }
        }
        count = ans;
        for (int i = k; i < s.size(); i++) {
            if (isVowel(s[i])) {
                count++;
            }
            if (isVowel(s[i-k])) {
                count--;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};