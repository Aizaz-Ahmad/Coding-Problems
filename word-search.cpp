//https://leetcode.com/problems/word-search/

class Solution {
private:
    bool exist(vector<vector<char>>& board, string& word, int r, int c, int i){
        //check if the word is formed or not
        if(i == word.size()) return true;
        
        if(//boundry checks
          r < 0 || c < 0 || r >= board.size() || c >= board[0].size()
           //check if the word can be formed by including the cell or not
           || board[r][c] != word[i]
           // check if the cell is already visited or not
           || board[r][c] == '\0') return false;
        char temp = board[r][c];
        board[r][c] = '\0';
        if(exist(board, word, r, c + 1, i + 1) ||
          exist(board, word, r, c - 1, i + 1) ||
          exist(board, word, r + 1, c, i + 1)||
          exist(board, word, r - 1, c, i + 1)) return true;
        board[r][c] = temp;
        return false;
        
    }
public:
    
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size(), cols = board[0].size();
        //loop over every cell and try to find the combination
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
                //check if the word can be formed from the current cell, skip if not possible 
                if(board[i][j] == word[0] && exist(board, word, i, j, 0)) return true;
        return false;
    }
};
