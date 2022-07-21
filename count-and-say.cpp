//https://leetcode.com/problems/count-and-say/

class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string count = countAndSay(n - 1);
        string res = "";
        int l = 0, r = 0;
        int  len = count.size();
        while(r < len){
            if(count[l] != count[r]){
                res = res + to_string(r - l) + "" + count[l];
                l = r;
            }else r++;
        }
        res = res + to_string(r - l) + "" + count[l];
        return res;
    }
};
