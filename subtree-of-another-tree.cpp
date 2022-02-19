//https://leetcode.com/problems/subtree-of-another-tree/
//https://leetcode.com/problems/missing-number/discuss/69777/C%2B%2B-solution-using-bit-manipulation
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int start = 0, end = nums.size();
        int sum = 0;
        //calculate their sum
        for(int i = 0; i <= end; i++)
            sum += i;
        //instead use int sum = (0+len)*(len+1)/2; n * (n + 1) / 2 for sum of numbers from 0 - n
        //subtract, so that the only missing number will be left of
        for(int i = 0; i < end; i++)
            sum -= nums[i];
        return sum;
    }
};
