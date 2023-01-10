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
    void tra(TreeNode* root, bool left, vector<int>& v){
        if(!root) return;
        if(root->left)tra(root->left,true, v);
        if(left) v.push_back(-root->val);
        else v.push_back(root->val);
        if(root->right)tra(root->right,false, v);
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> v1, v2;
        tra(p, true, v1);
        tra(q, true, v2);
        return (v1 == v2);
    }
};