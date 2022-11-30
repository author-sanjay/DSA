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
    vector<int> solve(TreeNode* root,vector<int > &ans){
        if(root==NULL){
            return ans;
        }
        solve(root->left,ans);
        ans.push_back(root->val);
        solve(root->right,ans);
        return ans;
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> ans;
        solve(root,ans);
        
        TreeNode* newnode=new TreeNode(ans[0]);
        TreeNode* curr=newnode;
        for(int i=1;i<ans.size();i++){
            TreeNode* child=new TreeNode(ans[i]);
            curr->left=NULL;
            curr->right=child;
            curr=child;
        }
        
        curr->left=NULL;
        curr->right=NULL;
        return newnode;
    }
};