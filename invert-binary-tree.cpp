//https://leetcode.com/problems/invert-binary-tree/

class Solution {
    
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        // return leaf node
        if(!root->left && !root->right) return root;
        //swap left node with right, bottom up approach
        TreeNode* temp = invertTree(root->left);
        root->left = invertTree(root->right);
        root->right = temp;
        // return the root node of the current subtree 
        return root;
    }
};
