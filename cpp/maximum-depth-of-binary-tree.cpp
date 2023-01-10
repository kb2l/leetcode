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
    int mx = 0;
    void dfs(TreeNode* root, int d) {
        if(!root) return;
        if(root->left) dfs(root->left, 1+d);
        mx = max(d, mx);
        if(root->right) dfs(root->right, 1+d);
    }
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        dfs(root, 1);
        return mx;
    }
};