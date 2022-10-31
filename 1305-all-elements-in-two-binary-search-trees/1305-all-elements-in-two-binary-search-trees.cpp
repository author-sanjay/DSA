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
    void inorder(TreeNode* root,vector<int> &arr){
        if(root==NULL){
            return;
        }
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>arr1;
        
        inorder(root1,arr1);
        for(auto a:arr1){
            cout<<a;
        }
        inorder(root2,arr1);
        sort(arr1.begin(),arr1.end());
        return arr1;
    }
};