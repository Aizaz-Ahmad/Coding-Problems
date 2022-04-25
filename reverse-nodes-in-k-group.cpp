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
class ImprovedSolution {
    ListNode* reverse(ListNode* head, ListNode* tail){
        ListNode* nextChunkHead = tail->next;
        ListNode* prev = nextChunkHead;
        while(head != nextChunkHead){
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        ListNode* temp = &dummy;
        temp->next = head;
        ListNode* prev = temp;
        ListNode* h = head,* tail = head;
        while(true){
            for(int i = 0; i < k - 1 && tail; i++)
                tail = tail->next;
            if(tail){
                ListNode* nextChunkHead = tail->next;
                prev->next = reverse(h, tail);
                prev = h;
                h = tail = nextChunkHead;
            }
            else break;
        }   
        return dummy.next;
    }
};
