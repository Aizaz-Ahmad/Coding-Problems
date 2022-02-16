// https://leetcode.com/problems/set-matrix-zeroes/
//Check other solution
class ExtraSpaceSolution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int R = matrix.size(), C = matrix[0].size();
        unordered_map<int, int> rows, cols;
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if(matrix[i][j] == 0){
                    rows.insert({i, 0});
                    cols.insert({j, 0});
                }
            }
        }
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if(rows.count(i) || cols.count(j))
                    matrix[i][j] = 0;
            }
        }
    }
};
