// https://leetcode.com/problems/merge-nodes-in-between-zeros/

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
       ListNode dummy(0);
        ListNode* temp = &dummy;
        head = head->next;
        int sum = 0;
        while(head){
            if(head->val == 0){
                head->val = sum;
                sum = 0;
                temp->next = head;
                temp = temp->next;
            }
            else sum += head->val;
            head = head->next;
        }
        return dummy.next;
    }
};
