//https://leetcode.com/problems/flatten-binary-tree-to-linked-list


class Solution {
    
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        TreeNode k(0);
        TreeNode* d = &k;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* n;
        while(!s.empty()){
            d->right = s.top();
            d->left = NULL;
             n = s.top();
            s.pop();
            if(n->right) s.push(n->right);
            if(n->left) s.push(n->left);
            d = d->right;
        }
        root = k.right;
    }
};
