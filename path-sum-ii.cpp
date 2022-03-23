//https://leetcode.com/problems/path-sum-ii/

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
    void pathSum(TreeNode* root, int targetSum, vector<vector<int>>& results, vector<int>& res){
        if(!root){
            res.clear();
            return;
        }
        res.push_back(root->val);
        if(!root->left && !root->right && root->val == targetSum){
            results.push_back(res);
            res.clear();
            return;
        }
        vector<int> prev = res;
        pathSum(root->left, targetSum - root->val, results, res);
        pathSum(root->right, targetSum - root->val, results, prev);
        res = prev;
        
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> results;
        vector<int> result;
        pathSum(root, targetSum, results, result);
        return results;
    }
};
