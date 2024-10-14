/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* f(struct ListNode* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    struct ListNode *newHead = f(head->next);
    // struct ListNode *j = head->next;
    head->next->next = head;
    head->next = NULL;
    return newHead;
}



struct ListNode* reverseList(struct ListNode* head){
    // struct ListNode* p, *q, *r;
    // p=head;
    // q= NULL;
    // r=NULL;
    // while(p!=NULL){
    //     r=q;
    //     q=p;
    //     p=p->next;
    //     q->next=r;
    // }
    // head=q;
    return f(head);
}
