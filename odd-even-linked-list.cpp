// https://leetcode.com/problems/odd-even-linked-list

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
        ListNode evenDummy(0);
        ListNode oddDummy(0);
        ListNode* even = &evenDummy;
        ListNode* odd = &oddDummy; 
        ListNode* curr = head;
        int index = 1;
        while(curr){
            if(index % 2){
                odd->next = curr;
                odd = odd->next;
            }
            else{
                even->next = curr;
                even = even->next;
            }
            index++;
            curr = curr->next;
        }
        even->next = NULL;
        odd->next = evenDummy.next;
        return oddDummy.next;
    }
};
