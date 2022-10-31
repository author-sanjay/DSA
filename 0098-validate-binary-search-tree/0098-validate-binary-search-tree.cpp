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
    void inorder(vector<int>&arr,TreeNode* root){
        if(root==NULL){
            return;
        }
        
        inorder(arr,root->left);
        arr.push_back(root->val);
        inorder(arr,root->right);
        
    }
    bool isValidBST(TreeNode* root) {
        vector<int> arr;
        inorder(arr,root);
        for(auto a:arr){
            cout<<a<<" ";
        }
        for(int i=1;i<arr.size();i++){
            if(arr[i]<=arr[i-1]){
                return false;
            }
        }
        return true;
    }
};