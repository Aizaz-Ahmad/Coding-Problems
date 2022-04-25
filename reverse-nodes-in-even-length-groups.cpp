// https://leetcode.com/problems/reverse-nodes-in-even-length-groups


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
    ListNode* reverse(ListNode* left, ListNode* right){
        ListNode* nextRight = right->next;
        ListNode* curr = left;
        ListNode* next = NULL,* prev = nextRight;
        while(curr != nextRight){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* c = head;
        ListNode* tail = head, *prev = head;
        ListNode* nextGroup = NULL;
        int groupSize = 1;
        while(head){
            int count = 1;
          // ... tail && tail->next) if it's last then tail should not be allowed
            while(count < groupSize && tail && tail->next){
                tail = tail->next;
                count++;
            }
            ListNode* nextGroup = tail ? tail->next : NULL;
            if(count % 2 == 0){
                prev->next = reverse(head, tail);
            prev = head;
            }else prev = tail;
            head = tail =  nextGroup;
            groupSize++;
        }
        return c;
    }
};
