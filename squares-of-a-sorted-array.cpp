// https://leetcode.com/problems/squares-of-a-sorted-array/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> squares(nums.size(), 0);
        int l = 0, r = nums.size() - 1;
        int i = nums.size() - 1;
        while(l <= r){
            if(abs(nums[l]) < abs(nums[r])){
                squares[i--] = nums[r] * nums[r];
                r--;
            }
            else{
                squares[i--] = nums[l] * nums[l];
                l++;
            }
        }
        return squares;
    }
};
