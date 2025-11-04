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
    int dfs(TreeNode* root, int maxSoFar) {
        if (!root) return 0;
        int good = (root->val >= maxSoFar) ? 1 : 0;
        int nextMax = max(root->val, maxSoFar);
        return good + dfs(root->left, nextMax) + dfs(root->right, nextMax);
    }

    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};