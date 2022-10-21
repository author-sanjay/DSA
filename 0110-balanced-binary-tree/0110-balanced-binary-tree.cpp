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
    
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        
        int leftside=height(root->left);
        int rightside=height(root->right);
        
        return max(leftside,rightside)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }    
        
        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);
        
        bool third=abs(height(root->left)-height(root->right))<=1;
        
        if(left && right && third){
            return true;
        }
        
        return false;
    }
};