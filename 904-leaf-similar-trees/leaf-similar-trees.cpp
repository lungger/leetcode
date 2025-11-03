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
    void findleaf(TreeNode* root, vector<int> &leaf) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right) {
            leaf.push_back(root->val);
        }

        findleaf(root->left, leaf);
        findleaf(root->right, leaf);
        return;
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        findleaf(root1, leaf1);
        findleaf(root2, leaf2);

        return leaf1 == leaf2;
    }

private:
    vector<int> leaf1;
    vector<int> leaf2;
};