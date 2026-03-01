class TrieNode {
public:
    TrieNode * childNodes[26];
    bool isEnd;
    TrieNode() {
        for (auto& i : childNodes) i = nullptr;
        isEnd = false;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *p = root;
        for (auto &a : word) {
            int i = a - 'a';
            if (!p->childNodes[i]) p->childNodes[i] = new TrieNode();
            p = p->childNodes[i];
        }
        p->isEnd = true;
    }
    
    bool search(string word, bool prefix = false) {
        TrieNode *p = root;
        for (auto &a : word) {
            int i = a - 'a';
            if (!p->childNodes[i]) return false;
            p = p->childNodes[i];
        }
        if (prefix==false) return p->isEnd;
        return true;
    }
    
    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */