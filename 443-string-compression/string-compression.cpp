class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> s;
        int count = 1;
        char prev = chars[0];
        for (int i = 1; i < chars.size(); i++) {
            if (chars[i] == prev) {
                count++;
            }
            else {
                s.push_back(prev);
                if (count != 1) {
                    std::string temp = std::to_string(count);
                    for (auto c : temp) {
                        s.push_back(c);
                    }
                    count = 1;
                }
            }
            prev = chars[i];
        }
        s.push_back(prev);
        if (count != 1) {
            std::string temp = std::to_string(count);
            for (auto c : temp) {
                s.push_back(c);
            }
            count = 1;
        }
        chars = s;
        return chars.size();
    }
};