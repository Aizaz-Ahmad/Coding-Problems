// https://leetcode.com/problems/count-complete-tree-nodes

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void countNodes(TreeNode* root, int& count){
        if(!root) return;
        if(root->left || (!root->left && !root->right)) count++;
        countNodes(root->left, count);
        countNodes(root->right, count);
    }
public:
    int countNodes(TreeNode* root) {
        int count = 0;
        countNodes(root, count);
        return count;
    }
};
