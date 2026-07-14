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
    int f( TreeNode *node , unordered_map<TreeNode* , int>&dp ){
        if( node == nullptr ) return 0;
        if(dp.count(node)) return dp[node];
       int robCurrent = node->val;
        if (node->left) {
            robCurrent += f(node->left->left , dp);
            robCurrent += f(node->left->right , dp);
        }

        if (node->right) {
            robCurrent += f(node->right->left ,dp);
            robCurrent += f(node->right->right,dp);
        }
        int skipnode = f(node->left,dp) + f(node->right,dp);

        return dp[node] =  max(robCurrent , skipnode);
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode* , int>dp;
        return f(root , dp);
    }
};