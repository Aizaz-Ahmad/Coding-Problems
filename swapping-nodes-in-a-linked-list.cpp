//https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* first = head, *second = head;
        if(!head->next) return head;
        int counter = 1;
        while(counter != k){
            first = first->next;
            counter++;
        }
        ListNode* temp = first;
        while(temp->next){
            temp = temp->next;
            second = second->next;
        }
        if(first == second) return head;
        first->val += second->val;
        second->val = first->val - second->val;
        first->val -= second->val;
        return head;
    }
};
