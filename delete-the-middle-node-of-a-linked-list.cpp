// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow = head, *fast = head, *prev = NULL;
        if(!head) return NULL;
        if(!head->next){
            delete head;
            return NULL;
        }
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = slow->next;
        delete slow;
        return head;
    }
};
