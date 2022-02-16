// https://leetcode.com/problems/climbing-stairs

class DPSolution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }
};

//
class FibonacciSolution {
public:
    int climbStairs(int n) {
        if(n == 0 || n == 1) return 1;
        int stepOne = 1, stepTwo = 1;
        int result = 0;
        for(int i = 2; i <= n; i++){
            result = stepOne + stepTwo;
            stepTwo = stepOne;
            stepOne = result;
        }
        return result;
    }
};
