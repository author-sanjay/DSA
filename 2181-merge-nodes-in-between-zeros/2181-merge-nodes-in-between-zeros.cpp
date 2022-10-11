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
    ListNode* mergeNodes(ListNode* head) {
        
        int x = 0;
        ListNode* temp = head;
        ListNode* q = head;
        ListNode* r;
        ListNode* ans = q;
        while(temp!=NULL){
            if(x > 0 && temp->val == 0){
                q->val = x;
                x = 0;
                r = q;
                q = q->next;
            }
            x += temp->val;
            temp = temp->next;
        }
        r->next = NULL;
        return ans;
        
    }
};