//https://leetcode.com/problems/valid-palindrome/

class Solution {
private:
    bool isAlphaNumeric(char a){
        return isalpha(a) || isdigit(a);
    }
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.length() - 1;
        while(l <= r){
            while(l <= r && !isAlphaNumeric(s[l])) l++;
            while(l <= r && !isAlphaNumeric(s[r])) r--;
            if(l <= r && tolower(s[l]) != tolower(s[r]))
                return false;
            l++;
            r--;
        }
        return true;
    }
};
