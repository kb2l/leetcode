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
    
    bool isValid(TreeNode* root, long h, long l){
        if(!root) return true;
        if(root->val >= h || root->val <= l) return false;
        bool ret = true;
        if(root->left)  ret &= isValid(root->left, root->val, l);
        if (root->right) ret &= isValid(root->right, h, root->val);
        return ret;
    }
    bool isValidBST(TreeNode* root) {
       return isValid(root,numeric_limits<long>::max(), numeric_limits<long>::min());
    }
};