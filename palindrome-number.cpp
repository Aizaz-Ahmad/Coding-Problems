// https://leetcode.com/problems/palindrome-number

class Solution {
public:
    bool isPalindrome(int x) {
        //if the number is negative, or if the last digit is zero
        // and first number is non-zero than the number is not-palindrome
        if(x < 0 || (x % 10 == 0 && x != 0)) return false;
        //revert the number by getting the last digit and multiplying it by 10 and add to prev number
        // if the number becomes greater than the original number than it is meant that we have traverresed
        //half the number
        int revert = 0;
        while(x > revert){
            revert = revert * 10 + x % 10;
            x /= 10;
        }
        //check if they are same, if they are odd digits,
        //than try removing the middle digit (n/10) and check again
        return x == revert || x == revert / 10;
    }
};
