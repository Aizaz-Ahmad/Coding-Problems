// https://leetcode.com/problems/unique-paths/

class RecursiveSolution {
public:
    int uniquePaths(int m, int n) {
        if(m < 0 || n < 0) return 0; // if they index underflow
        if(m == 1 || n == 1) return 1; // when it contains 1 row or column, there is only one unique path 
        // uniquePaths(m - 1, n) - move robot to bottom, similarly uniquePaths(m, n - 1) - move robot to right
        return uniquePaths(m - 1, n) + uniquePaths(m, n - 1); 
    }
};

class DPSolution {
public:
    int uniquePaths(int m, int n) {
        //Each cell will contain the number of unique paths from that position
        vector<vector<int>> dp(m, vector<int> (n, 0));
        //initialize last column and last row with 1 -
        //because there is only one unique path to reach end when matrix is row or column
        for(int i = 0; i < n; i++)
            dp[m - 1][i] = 1;
        for(int i = 0; i < m; i++)
            dp[i][n - 1] = 1;
        //moving back from right to left and then bottom to top, and summing the bottom and right cell.
        for(int i = m - 2; i >=0; i--)
            for(int j = n - 2; j >= 0; j--)
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
        //solution will be in the first cell
        return dp[0][0];
    }
};
