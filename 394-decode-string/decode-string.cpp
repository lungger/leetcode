class Solution {
public:
    string decodeString(string s) {
        stack<int>  numStack;
        stack<string> stringStack;
        string tempS = "";
        int num = 0;

        for (auto c : s) {
            if (c >= 'a' && c <= 'z') {
                tempS += c;
            }
            else if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            else if (c == '[') {
                numStack.push(num);
                num = 0;
                stringStack.push(tempS);
                tempS = "";
            }
            else if (c == ']') {
                num = numStack.top();
                numStack.pop();
                string t = stringStack.top();
                stringStack.pop();
                while (num > 0) {
                    t += tempS;
                    num--;
                }
                tempS = t;
            }
        }

        return tempS;
    }
};