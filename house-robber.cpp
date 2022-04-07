// https://leetcode.com/problems/house-robber

class Solution {
public:
    int rob(vector<int>& nums) {
        //dp[i] represents the maximum that can be robbed from [ith...n] houses
        vector<int> dp(nums.size(), 0);
        size_t n = nums.size();
        if(n == 1) return nums[0];
        // [1, 2, 3, 1] -> dp[n - 1] = 1 because dp[3] = 1
        dp[n - 1] = nums[n - 1];
        // [1, 2, 3, 1] -> dp[n - 2] = 3 because dp[2] = 3
        dp[n - 2] = max(nums[n - 2], nums[n - 1]);
        // [1, 2, 3, 1] -> dp[1] = max(money from skipping ith house, money from including that house
        // + money that can be robbed from [ith + 2]
        for(int i = n - 3; i >= 0; i--)
            dp[i] = max(dp[i + 1], nums[i] + dp[i + 2]);
        // maximum that can be robbed from [0...n] i.e. the maximum from all the houses
        return dp[0];
    }
};
