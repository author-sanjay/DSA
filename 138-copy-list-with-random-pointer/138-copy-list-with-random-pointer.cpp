/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    
    void insertattail(Node* &head,Node* &tail, int val){
        Node* temp=new Node(val);
        if(head==NULL){
            head=temp;
            tail=temp;
            return ;
        }else{
            tail->next=temp;
            tail=temp;
        }
    }
    Node* copyRandomList(Node* head) {
        Node* cloneHead=NULL;
        Node* cloneTail=NULL;
        
        Node* temp=head;
        
        while(temp!=NULL){
            insertattail(cloneHead,cloneTail,temp->val);
            temp=temp->next;
        }
        
        unordered_map<Node*, Node*> mp;
        Node* original=head;
        Node* copy=cloneHead;
        
        while(original!=NULL && copy!=NULL){
            mp[original]=copy;
            original=original->next;
            copy=copy->next;
        }
        
        original=head;
        copy=cloneHead;
        while(original!=NULL && copy!=NULL){
            copy->random=mp[original->random];
            original=original->next;
            copy=copy->next;
        }
        
        return cloneHead;
    }
};