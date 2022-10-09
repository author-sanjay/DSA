/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* merge2(ListNode* first,ListNode* second){
        if(first==NULL){
            return second;
        }
        if(second==NULL){
            return first;
        }
        
        ListNode* send=new ListNode(-1);
        ListNode* temp= send;
        ListNode* tail=send;
        
        while(first!=NULL && second!=NULL){
            if(first->val<second->val){
                tail->next=first;
                first=first->next;
            }
            
            else{
                tail->next=second;
                second=second->next;
            }
            tail=tail->next;
        }
        
        
        if(first!=NULL){
            tail->next=first;
        }
        
        if(second!=NULL){
            tail->next=second;
        }
        
        
        return send->next;
    }
    
    ListNode* divide(vector<ListNode*>& lists,int start,int end){
        if(start>end){
            return NULL;
        }
        if(start==end){
            return lists[start];
        }
        
        int mid=(start+end)/2;
        ListNode* l1=divide(lists,start,mid);
        ListNode* l2=divide(lists,mid+1,end);
        
        return merge2(l1,l2);
    
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        return divide(lists,0,lists.size()-1);
        
    }
};