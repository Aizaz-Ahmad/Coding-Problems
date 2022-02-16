// https://leetcode.com/problems/binary-tree-level-order-traversal/
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
private: 
    int getHeightOfTree(TreeNode *root, int depth){
        if(root == NULL) return depth;
        return max(getHeightOfTree(root->left, depth + 1), getHeightOfTree(root->right, depth + 1)); 
    }
    void levelOrder(TreeNode* root, int depth, vector<vector<int>>& result){
        if(!root) return;
        result[depth].push_back(root->val);
        levelOrder(root->left, depth + 1, result);
        levelOrder(root->right, depth + 1, result);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        int height = getHeightOfTree(root, 0);
        if(!height) return vector<vector<int>>();
        
        vector<vector<int>> result(height, vector<int>());
        
        levelOrder(root, 0, result);
        
        return result;
    }
};


class ImprovedSolution {
private: 
    void levelOrder(TreeNode* root, int depth, vector<vector<int>>& result){
        if(!root) return;
        //increase the size, instead of getting the height
        if(result.size() == depth)
            result.push_back(vector<int>());
        
        result[depth].push_back(root->val);
        levelOrder(root->left, depth + 1, result);
        levelOrder(root->right, depth + 1, result);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> result;
        
        levelOrder(root, 0, result);
        
        return result;
    }
};
