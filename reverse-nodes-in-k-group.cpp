// https://leetcode.com/problems/reverse-nodes-in-k-group/

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode* curr = head;
        while(curr && count != k){
            curr = curr->next;
            count++;
        }
        // there are k nodes available
        if(count == k){
            curr = reverseKGroup(curr, k); //curr - pointer to head of reverse part
            //head pointer to straight part
            
            //reverse current k nodes
            while(count-- > 0){
                ListNode* next = head->next;
                head->next = curr;
                curr = head;
                head = next;
            }
            head = curr;
        }
        return head;
    }
};
