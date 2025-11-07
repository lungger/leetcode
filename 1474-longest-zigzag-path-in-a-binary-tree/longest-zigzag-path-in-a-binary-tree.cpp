/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int longestZigZag(TreeNode* root) {
        dfs(root->left, 1, false);
        dfs(root->right, 1, true);
        return count;
    }

    void dfs(TreeNode* root, int currLen, bool direction) {
        if (!root) {
            return;
        }

        count = max(currLen, count);
        dfs(root->left,  direction ? currLen + 1 : 1, false);
        dfs(root->right,  direction ? 1 : currLen + 1, true);
    }

private:
    int count = 0;
};