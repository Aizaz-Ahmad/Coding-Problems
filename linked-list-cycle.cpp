//https://leetcode.com/problems/linked-list-cycle/
//https://leetcode.com/problems/linked-list-cycle/discuss/44669/Fully-Explained!-why-fast-and-slow-can-meet-in-the-cycle
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* curr = head;
        while(curr) {
            if(curr->val == INT_MIN) return true;
            curr->val = INT_MIN;
            curr = curr->next;
        }
        return false;
    }
};
