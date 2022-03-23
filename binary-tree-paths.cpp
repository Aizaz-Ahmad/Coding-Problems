//https://leetcode.com/problems/binary-tree-paths/
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
    void binaryTreePaths(TreeNode* root, vector<string>& paths, string& path){
        if(root == NULL)
            return;
        
        path +=  to_string(root->val) + "->";

        if(!root->left && !root->right){
             paths.push_back(path.substr(0, path.size() - 2));
            path = "";
            return;
        }
        string prev = path;
        binaryTreePaths(root->left, paths, path);
        binaryTreePaths(root->right, paths, prev);
        path = prev;
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
         vector<string> res;
        string path = "";
        binaryTreePaths(root, res, path);
        return res;
    }
};
