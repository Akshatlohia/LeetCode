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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL)return head;
        ListNode *i = head;
        ListNode *j = head->next;
        ListNode *h2 = j;
        while(j && j->next){
            i->next = i->next->next;
            j->next = j->next->next;
            i = i->next;
            j = j->next;
        }
        // i->next = i->next->next;
        // j->next = j->next->next;
        i->next = h2;
        return head;


    }
};