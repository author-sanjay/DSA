
class Solution {
public:
    
    TreeNode* create(vector<int> arr,int start,int end){
        if(start>end){
            return NULL;
        }
        int mid=(start+end)/2;
        TreeNode* root=new TreeNode(arr[mid]);
        root->left=create(arr,start,mid-1);
        root->right=create(arr,mid+1,end);
        return root;
        
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        vector<int> inorder;
        ListNode* curr=head;
        while(curr!=NULL){
            inorder.push_back(curr->val);
            curr=curr->next;
        }
        
        return create(inorder,0,inorder.size()-1);
    // return NULL;
        
    }
};