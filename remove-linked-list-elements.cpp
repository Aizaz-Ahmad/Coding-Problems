// https://leetcode.com/problems/remove-linked-list-elements

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode newHead(0);
        ListNode* temp = &newHead;
        while(head){
            if(head->val != val){
                temp->next = head;
                temp = temp->next;
            }
            head = head->next;
        }
        temp->next = NULL;
        return newHead.next;
    }
};
