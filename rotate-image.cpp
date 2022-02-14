// https://leetcode.com/problems/rotate-image/
// https://www.youtube.com/watch?v=SA867FvqHrM

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        size_t n = matrix.size();
        if(n == 1) return;
        //as it is rotation by 90 deg which means, 1st row will become last column
        //transpose the matrix, make first row, first column
        for(size_t i = 0; i < n;i++)
            for(size_t j = i; j < n; j++)
                swap(matrix[i][j], matrix[j][i]);
        //flipping it horizontly, to make first column, last column
        for(size_t i = 0; i < n;i++)
                reverse(matrix[i].begin(), matrix[i].end());
        
    }
};
