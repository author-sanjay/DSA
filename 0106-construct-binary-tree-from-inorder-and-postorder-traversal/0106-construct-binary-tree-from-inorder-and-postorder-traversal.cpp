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
    int findpos(int ele,vector<int>inorder){
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==ele){
                return i;
            }
        }
        return -1;
    }
    TreeNode* solve(vector<int> inorder,vector<int> postorder,int &index,int inorderstart, int inorderend,int end){
        if(index<0 || inorderstart>inorderend){
            return NULL;
        }
        
        int ele=postorder[index--];
        TreeNode* node = new TreeNode(ele);
        int pos=findpos(ele,inorder);
        
        node->right=solve(inorder,postorder,index,pos+1,inorderend,end);

        node->left=solve(inorder,postorder,index,inorderstart,pos-1,end);
                
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size()-1;
        TreeNode* root=solve(inorder,postorder,n,0,postorder.size()-1,0);
        return root;
        
    }
};