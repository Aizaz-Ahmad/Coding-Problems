// https://leetcode.com/problems/recover-binary-search-tree


class MemorySolution {
    void inOrder(TreeNode* root, vector<int>& res){
        if(!root) return;
        inOrder(root->left, res);
        res.push_back(root->val);
        inOrder(root->right, res);
    }
    void construct(TreeNode* root, vector<int>& res){
        if(!root) return;
        construct(root->left, res);
        root->val = res.back();
        res.pop_back();
        construct(root->right, res);
    }
public:
    void recoverTree(TreeNode* root) {
        vector<int> res;
        inOrder(root, res);
        sort(res.begin(), res.end(), greater<int>());
        construct(root, res);
    }
};
