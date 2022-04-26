// https://leetcode.com/problems/validate-binary-search-tree/
class Solution {
private:
    TreeNode* prev;
    bool inOrder(TreeNode* root){
        if(root == NULL) return true;
        if(!inOrder(root->left)) return false;
        if(prev != NULL && root->val <= prev->val)
            return false;
        prev = root;
        if(!inOrder(root->right)) return false;
        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        this->prev = NULL;
        return inOrder(root);
    }
};
