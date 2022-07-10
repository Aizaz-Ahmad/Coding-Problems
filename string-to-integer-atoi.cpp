// https://leetcode.com/problems/string-to-integer-atoi/

class Solution {
public:
    int myAtoi(string str) {
        int readIdx = 0;
        while(str[readIdx] == ' ') readIdx++;
        bool isPositive = true;
        if(str[readIdx] == '-' || str[readIdx] == '+'){
            if(str[readIdx] == '-') isPositive = false;
            readIdx++;
        }
        int res  = 0;
        while(readIdx < str.length() && isdigit(str[readIdx])){
            int digit = str[readIdx] - '0';
            if((res > INT_MAX / 10) || (res == INT_MAX / 10 && digit > INT_MAX % 10))
               return isPositive ? INT_MAX : INT_MIN;
            res = res * 10 + digit;
            readIdx++;
        }
        return isPositive ? res : -res;
    }
};
