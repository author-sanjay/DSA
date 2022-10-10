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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        
        if(count==0){
            head=NULL;
        }else if(count==n){
            head=head->next;
            return head;
        }
        int i=0;
        temp=head;
        while(temp){
            if(i==count-n-1){
                temp->next=temp->next->next;
            }else{
                temp=temp->next;
            }
            i++;
        }

        
        
        return head;
    }
};