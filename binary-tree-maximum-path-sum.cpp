// https://leetcode.com/problems/binary-tree-maximum-path-sum/
//Explaination: https://leetcode.com/problems/binary-tree-maximum-path-sum/discuss/603072/C%2B%2B-solution-O(n)-with-detailed-explanation
// https://leetcode.com/problems/binary-tree-maximum-path-sum/discuss/389609/Full-Explanation-article-with-pseudo-code-Beats-JAVA-100-time-and-100-space-Solution
class Solution {
   //global variable to store the maxSum
    int maxSum;
    //maximumSum in the subtrees of root
    int _maxSum(TreeNode* root){
        // if leave node then return 0 i.e. no max sum path exists
        if(!root) return 0;
        //postorder traversal, check wheather to include left, right or both nodes in the solution
        // l - if sum in left subtree < 0 then we exclude that node, because it will make the totalSum < 0
        // r - same for the right node
        int l = max(_maxSum(root->left), 0);
        int r = max(_maxSum(root->right), 0);
        // if both l && r > 0 then both l and r will be selected to the maxSum
        int n = root->val + l + r;
        // update the maxSum 
        this->maxSum = max(this->maxSum, n);
        // return the sum in the current root
        return root->val + max(l, r);
    }
public:
    int maxPathSum(TreeNode* root) {
        this->maxSum = INT_MIN;
        _maxSum(root);
        return maxSum;
    }
};
