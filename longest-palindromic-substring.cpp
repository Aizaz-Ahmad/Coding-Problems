//https://leetcode.com/problems/longest-palindromic-substring
// O(n ^ 2) time and space complexity
class DPSolution {
public:
    string longestPalindrome(string s) {
        size_t size = s.length();
        if(size == 1) return s;
        int maxLength = 1, start = 0, end = 1;
        bool table[size][size];
        memset(table, 0, size * size);
        for(int i = 0; i < size; i++)
            table[i][i] = 1;
        
        for(int i = 0; i < size - 1; i++){
            if(s[i] == s[i + 1]){
                table[i + 1][i] = table[i][i + 1] = 1;
                maxLength = 2;
                start = i;
            }
        }
        //fill up diagonaly
        for(int k = 3; k <= size; ++k){
            for(int i = 0; i < size - k + 1; ++i){
                int j = i + k - 1;
                table[i][j] = (table[i + 1][j - 1] && s[i] == s[j]);
                if(table[i][j] && maxLength < (j - i + 1)){
                    maxLength = j - i + 1;
                    start = i;
                    end = j;
                }
            }
        }
        
        return s.substr(start, maxLength);
    }
};
