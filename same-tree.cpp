// https://leetcode.com/problems/same-tree/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //check if both nodes are null, then return true
        if(!p && !q) return true;
        //check if any one of the node is null, return false;
        if(!p || !q) return false;
        //if values are not same, return false
        if(p->val != q->val) return false;
        //if the left subtree is same, then check for right subtree, otherwise return fasle
        if(isSameTree(p->left, q->left))
            return isSameTree(p->right, q->right);
        else return false;
    }
};
