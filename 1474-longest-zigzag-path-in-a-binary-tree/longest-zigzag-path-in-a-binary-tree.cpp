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
        if (direction) {
            dfs(root->left, currLen+1, !direction);
            dfs(root->right, 1, direction);
        }
        else {
            dfs(root->left, 1, direction);
            dfs(root->right, currLen+1, !direction);
        }
    }

private:
    int count = 0;
};