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
    
    bool checkk(ListNode* head, int k){
        ListNode *curr=head;
        int count1=0;
        while(curr!=NULL){
            curr=curr->next;
            count1++;
        }
        
        if(count1<k){
            return false;
        }
        
        return true;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL){
            return NULL;
        }
        
        if(checkk(head,k)==false){
            return head;
        }
        
        
        int count=0;
        ListNode *prev=NULL;
        ListNode *curr=head;
        ListNode *next=NULL;
        
        while(curr!=NULL && count<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        
        if(next!=NULL){
            head->next =reverseKGroup(next,k);
        }
        
        return prev;
        
    }
};