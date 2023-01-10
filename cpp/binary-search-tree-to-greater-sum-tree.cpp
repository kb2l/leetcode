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
    void bfs(TreeNode* root, int& propagate){
        if(root == nullptr) return;
        bfs(root->right, propagate);
        root->val += propagate;
        propagate = root->val;
        bfs(root->left, propagate);
        
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        int p = 0;
        bfs(root, p);
        return root;
    }
};