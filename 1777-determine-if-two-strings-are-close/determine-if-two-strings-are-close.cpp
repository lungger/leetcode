class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_set<char> chSet1;
        unordered_set<char> chSet2;

        unordered_map<char, int> freq1;
        unordered_map<char, int> freq2;

        unordered_map<int, int> freqOfFreq1;
        unordered_map<int, int> freqOfFreq2;

        for (char c : word1) {
            chSet1.insert(c);
            ++freq1[c];
        }

        for (char c : word2) {
            chSet2.insert(c);
            ++freq2[c];
        }

        if (chSet1 != chSet2) {
            return false;
        }

        for (auto& [c, freq] : freq1) {
            ++freqOfFreq1[freq];
        }

        for (auto& [c, freq] : freq2) {
            ++freqOfFreq2[freq];
        }

        return freqOfFreq1 == freqOfFreq2;
    }
};