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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* Newhead = new ListNode(-1);
        ListNode *t = Newhead ;
        ListNode *Curr = head;

        while(Curr)
        {
            if(Curr->val != val)
            {
                ListNode* temp = new ListNode(Curr->val);
                t->next = temp;
                t = t->next; 
            }
            Curr = Curr->next;
        }

    return Newhead ->next;
        
    }
};