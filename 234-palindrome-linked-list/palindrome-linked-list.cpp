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
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head,*fast=head,*prev=NULL,*curr=slow,*next=NULL;
        while (fast&& fast->next) {
            slow=slow->next;
            fast=fast->next->next;
        }
        curr=slow;
        
        while (curr) {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        //compare
        ListNode *f=head,*s=prev;
        while (s) {
            if (f->val!=s->val) 
                return false;
            f=f->next;
            s=s->next;
            
        }
        return true; 
    }
};