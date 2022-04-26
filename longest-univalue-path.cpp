// https://leetcode.com/problems/longest-univalue-path

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
/**
Intuition

We can think of any path (of nodes with the same values) as up to two arrows extending from it's root.

Specifically, the root of a path will be the unique node such that the parent of that node does not appear in the path, and an arrow will be a path where the root only has one child node in the path.

Then, for each node, we want to know what is the longest possible arrow extending left, and the longest possible arrow extending right? We can solve this using recursion.

Algorithm

Let arrow_length(node) be the length of the longest arrow that extends from the node. That will be 1 + arrow_length(node.left) if node.left exists and has the same value as node. Similarly for the node.right case.

While we are computing arrow lengths, each candidate answer will be the sum of the arrows in both directions from that node. We record these candidate answers and return the best one
**/
class Solution {
    int ans;
    int arrowLength(TreeNode* root){
        if(!root) return 0;
        int left = arrowLength(root->left);
        int right = arrowLength(root->right);
        int arrowLeft = 0, arrowRight = 0;
        if(root->left && root->left->val == root->val)
            arrowLeft += left + 1;
        if(root->right && root->right->val == root->val)
            arrowRight += right + 1;
        this->ans = max(this->ans, arrowLeft + arrowRight);
        //maximum arrow length from that node
        return max(arrowLeft, arrowRight);
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        ans = 0;
        arrowLength(root);
        return ans;
    }
};
