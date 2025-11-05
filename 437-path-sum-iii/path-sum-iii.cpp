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
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefix;
        prefix[0] = 1;
        dfs(root, targetSum, 0, prefix);

        return count;
    }

private:
    void dfs(TreeNode* root, int targetSum, long long curSum, unordered_map<long long, int> &prefix) {
        if (!root) {
            return;
        }

        curSum += root->val;
        count += prefix[curSum - targetSum];

        prefix[curSum]++;
        dfs(root->left, targetSum, curSum, prefix);
        dfs(root->right, targetSum, curSum, prefix);
        prefix[curSum]--;
    }

    int count = 0;
};