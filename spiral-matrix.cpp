//https://leetcode.com/problems/spiral-matrix
//https://leetcode.com/problems/spiral-matrix/discuss/20573/A-concise-C%2B%2B-implementation-based-on-Directions
class Solution {
private:
    void spiralOrder(vector<vector<int>>& matrix, vector<int>& res, int sr, int sc,
                    int er, int ec){
        if(sr > er || sc > ec) return;
        
        for(int i = sc; i <= ec; i++)
            res.push_back(matrix[sr][i]);
        sr++;
        for(int i = sr; i <= er;i++)
            res.push_back(matrix[i][ec]);
        ec--;
        if(sr > er) return;
        for(int i = ec; i >= sc; i--)
            res.push_back(matrix[er][i]);
        er--;
        if(sc > ec) return;
        for(int i = er; i >= sr; i--)
            res.push_back(matrix[i][sc]);
        sc++;
        spiralOrder(matrix, res, sr, sc, er, ec);
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int rows = matrix.size(), cols = matrix[0].size();
        
        spiralOrder(matrix, res, 0, 0, rows - 1, cols - 1);
        
        return res;
    }
};
