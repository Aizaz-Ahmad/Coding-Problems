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
