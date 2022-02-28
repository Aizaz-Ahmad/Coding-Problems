//https://leetcode.com/problems/rotate-array/
// https://leetcode.com/problems/rotate-array/discuss/54277/Summary-of-C%2B%2B-solutions
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        size_t size = nums.size();
        //after n rotations the array will be same as before
        k = k % size;
        for(int i = 0; i < k; i++){
            int last = nums[size - 1];
            int prev = nums[0];
            for(int j = 1; j < size; j++){
                int temp = nums[j];
                nums[j] = prev;
                prev  = temp;
            }
            nums[0] = last;
        }
    }
};
// O(n) time, O(1) space
class BetterSolution {
public:
    void rotate(vector<int>& nums, int k) {
        size_t size = nums.size();
        k = k % size;
        //reverse first n-k elements
        reverse(nums.begin(), nums.begin() + size - k);
        //reverse last k elements
        reverse(nums.begin() + size - k, nums.end());
        //reverse the whole array
        reverse(nums.begin(), nums.end());
    }
};
