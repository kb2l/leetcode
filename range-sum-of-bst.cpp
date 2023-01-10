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
    unsigned long sum = 0;
    void recur(TreeNode * node, int low, int high){
        if(!node) return;
        if(node->val < low) {
            recur(node->right, low, high);
        }
        else if(node->val > high) {
            recur(node->left, low, high);
        }
        else {
            sum += node->val;
            recur(node->right, low, high);
            recur(node->left, low, high);
        }
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        recur(root, low, high);
        return sum;
    }
};