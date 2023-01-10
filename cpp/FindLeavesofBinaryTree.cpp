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
    unordered_map<TreeNode*, bool> vis;
    TreeNode* orig = nullptr;
    
    vector<int> findLeavesCore(TreeNode* root)
    {
        if(!root) return {};
        if(orig == nullptr) orig = root;
        
        if(vis[root]) return {};
        
        vector<int> ret;
        if(
           (root->left == nullptr && root->right == nullptr) //leaf
           || 
           (
               (root->left && root->right) && (vis[root->left] && vis[root->right])
           )
           ||
           (
               (root->left && root->right == nullptr && vis[root->left])
           )
            ||
           (
               (root->right && root->left == nullptr && vis[root->right])
           )
            )
        {
            ret.push_back(root->val);
            vis[root] = true;
        }
        else
        {
            auto l = findLeavesCore(root->left), 
                r = findLeavesCore(root->right);
            for(auto e : l) ret.push_back(e);
            for(auto e : r) ret.push_back(e);
        }
        
        return ret;
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ret;
        while(!vis[orig]) ret.push_back(findLeavesCore(root));
        return ret;
    }
};