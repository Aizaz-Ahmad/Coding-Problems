//https://leetcode.com/problems/palindrome-linked-list

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
    ListNode* front;
    bool recursive(ListNode* node){
        //check if the node is not null
        if(node){
            //recurse to move the node to the last node, if the call return false, then function return false
            if(!recursive(node->next)) return false;
            //check if the values are same or not, if not same then return false
            if(node->val != front->val) return false;
            //move to the next pointer
            front = front->next;
        }
        //if the end of the list is reached or the front and current nodes are of same value
        return true;
    }
public:
    bool isPalindrome(ListNode* head) {
        this->front = head;
        return recursive(head);
    }
};
