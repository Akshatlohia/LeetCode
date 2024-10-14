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
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode *newHead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }

    bool isPalindrome(ListNode* head) {
        ListNode *i=head;
        ListNode *j=head;
        while(j->next && j->next->next){
            i = i->next;
            j = j->next->next;
        }
        ListNode *newHead = reverse(i->next);
        ListNode *k = head;
        j = newHead;
        while(j){
            if(j->val != k->val){
                reverse(newHead);
                return false;
            }
            j=j->next;
            k=k->next;
        }
        reverse(newHead);
        return true;

    }
};