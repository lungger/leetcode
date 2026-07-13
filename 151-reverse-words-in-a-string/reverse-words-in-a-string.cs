public class Solution {
    public string ReverseWords(string s) {
        StringBuilder sb = new StringBuilder();
        int len = s.Length;
        int pos = len;
        if (len == 1) {
            return s;
        }
        bool flag = true;
        if (s[len-1] == ' ') { 
            flag = false;
        }
        for (int i = len - 2; i > -1; i--) {
            if (s[i] != ' ' && !flag) {
                pos = i+1;
                flag = !flag;
            }
            else if (s[i] == ' ' && flag) {
                sb.Append(s.Substring(i+1, pos - (i + 1)));
                sb.Append(" ");
                flag = !flag;
            }
        }
        if (flag) {
            sb.Append(s.Substring(0, pos));
        } 
        else {
            sb.Remove(sb.Length - 1, 1);
        }
        return sb.ToString();
    }
}