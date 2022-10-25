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
    int findpos(vector<int> inorder,int ele){
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==ele){
                return i;
            }
        }
        
        return -1;
    }
    TreeNode* solve(vector<int> preorder,vector<int>inorder,int &index, int inorderindex,int inorderend,int end){
        
        if(index>=end || inorderindex>inorderend){
            return NULL;
        }
        
        int element=preorder[index++];
        TreeNode* node=new TreeNode(element);
        int pos=findpos(inorder,element);
        
        node->left=solve(preorder,inorder,index,inorderindex,pos-1,end);
        node->right=solve(preorder,inorder,index,pos+1,inorderend,end);
        
        return node;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       int preorderidx=0;
       TreeNode* root= solve(preorder,inorder,preorderidx,0,preorder.size()-1,preorder.size());
        return root;
    }
};