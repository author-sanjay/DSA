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
    vector<vector<int>>ans;
    
    void solve(TreeNode* root,int target,vector<int> &path){
        if(root==NULL){
            return; 
        }
        path.push_back(root->val);
        
        
        int newtarget=target-root->val;
        if(!root->left && !root->right){
            if(newtarget==0){
                ans.push_back(path);
            }

        }else{
            solve(root->left,newtarget,path);
            solve(root->right,newtarget,path);
        }
        path.pop_back();
        
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        solve(root,targetSum,path);
        return ans;
        
    }
};