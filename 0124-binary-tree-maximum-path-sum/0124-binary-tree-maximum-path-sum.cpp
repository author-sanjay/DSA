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
    int dfs(TreeNode* root,int &ans){
    if(root==NULL){
        return 0;
    }
    int left=dfs(root->left,ans);
    if(left<0){
        left=0;
    }
    int right=dfs(root->right,ans);
    if(right<0){
        right=0;
    }
    ans=max(ans,root->val+left+right);
    return root->val+max(left,right);
    
    
        
    }
    int maxPathSum(TreeNode* root) {
        int sum=INT_MIN;
        
        dfs(root,sum);
        return sum;
    }
};