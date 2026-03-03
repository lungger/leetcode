class TrieNode {
public:
    TrieNode* child[26];
    bool isEnd;
    TrieNode() {
        for(auto& i : child) i = nullptr;
        isEnd = false;
    }
};

class Solution {
public:
    void dfs(TrieNode* root, vector<string>& suggestions, string& temp) {
        if (root->isEnd) {
            if (!temp.empty())
                suggestions.push_back(temp);
        }

        for (int i = 0; i < 26; i++) {
            if (suggestions.size() == 3) return;
            if (root->child[i]) {
                temp += 'a' + i;
                dfs(root->child[i], suggestions, temp);
                temp.pop_back();
            }
        }
        
    }

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) { 
        TrieNode* root = new TrieNode();
        for (auto s : products) {
            TrieNode* p = root;
            for (auto c : s) {
                int i = c - 'a';
                if (!p->child[i]) p->child[i] = new TrieNode();
                p = p->child[i];
            }
            p->isEnd = true;
        }

        vector<vector<string>> ans;
        string temp = "";
        TrieNode* node = root;
        for (int i = 0; i < searchWord.size(); i++) {
            vector<string> suggestions;
            if (node) {
                node = node->child[searchWord[i]-'a'];
                temp += searchWord[i];
            }

            if (node) dfs(node, suggestions, temp);
            ans.push_back(suggestions);
        }
        return ans;
    }
};