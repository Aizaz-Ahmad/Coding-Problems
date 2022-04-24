// https://leetcode.com/problems/merge-two-binary-trees/

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
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return NULL;
        int val = (root1 ? root1->val : 0) + (root2 ? root2->val : 0);
        TreeNode* newNode = new TreeNode(val);
        newNode->left = mergeTrees(root1 ? root1->left: 0, root2 ? root2->left: 0);
        newNode->right = mergeTrees(root1 ? root1->right: 0, root2 ? root2->right: 0);
        return newNode;
    }
};
