// https://leetcode.com/problems/product-of-array-except-self
// https://leetcode.com/problems/product-of-array-except-self/discuss/135882/A-Java-solution-with-an-explanation

// O(n) time - O(n) space
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        size_t size = nums.size();
        vector<int> left (size);
        vector<int> right (size);
        vector<int> product (size);
        
        left[0] = 1;
        for(int i = 1; i < size; i++)
            left[i] = left[i - 1] * nums[i - 1];
        right[size - 1] = 1;
        for(int i = size - 2; i >= 0; i--)
            right[i] = right[i + 1] * nums[i + 1];
        
        for(int i = 0; i < size; i++)
            product[i] = left[i] * right[i];
        
        return product;
        
    }
};

// O(n) time - O(1) space

class Solution2 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        size_t size = nums.size();
        int left = 1, right = 1;
        vector<int> res (size, 1);
        
        for(int i = 0; i < size;i++){
             res[i] *= left;
             left *= nums[i];
            res[size - 1 - i] *= right;
            right *=nums[size - 1 - i];
        }
        
        return res;
        
    }
};
