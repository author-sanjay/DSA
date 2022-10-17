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

    bool solve(TreeNode* lroot,TreeNode* rroot){
        if(!lroot && !rroot){
            return true;
        }else if(lroot && rroot){
            bool c=(lroot->val ==rroot->val);
            if(c){
            bool a=solve(lroot->left,rroot->right);
            bool b=solve(lroot->right,rroot->left);
                return (a&&b);
            }else{
                return false;
            }
        }
        else return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root){
            return true;
        }
        return solve(root->left,root->right);
    }
};