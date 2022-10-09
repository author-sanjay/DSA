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
  
    ListNode* reverse(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* nextl=NULL;
        
        while(curr!=NULL){
            nextl=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextl;
        }
        
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        
        if(!head or !head->next)
            return true;
        
        ListNode* slow=head;
        ListNode* fast= head;
        
        while(fast->next and fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            
        }
        slow->next= reverse(slow->next);
        slow=slow->next;
        while(slow!=NULL)
        {
            if(head->val!=slow->val)
                return false;
            slow=slow->next;
            head=head->next;
        }
        return true;
        
    }
};