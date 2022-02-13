// https://leetcode.com/problems/merge-k-sorted-lists
// Check other approaches in other section
// O(k * n) time - O(1) Space, where k is number of lists

class Solution {
private:
     ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(INT_MIN);
        ListNode *tail = &dummy;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        size_t size = lists.size();
        if(size == 0) return NULL;
        if(size == 1) return lists[0];
        ListNode* prev = lists[0];
        ListNode* merged = NULL;
        for(size_t i = 0; i < size - 1; i++){
            merged = mergeTwoLists(prev, lists[i + 1]);
            prev = merged;
        }
        return merged;
    }
};
