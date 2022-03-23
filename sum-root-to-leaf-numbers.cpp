// https://leetcode.com/problems/sum-root-to-leaf-numbers/

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
    void sumNumbers(TreeNode* root, int& sum, string s){
        if(!root) return;
        s += to_string(root->val);
        if(!root->left && !root->right) {
            sum += stoi(s);
            return;
        } 
        sumNumbers(root->left, sum, s);
        sumNumbers(root->right, sum, s);
    }
public:
    int sumNumbers(TreeNode* root) {
        vector<string> res;
        int sum = 0;
        sumNumbers(root, sum, "");
        return sum;
    }
};
