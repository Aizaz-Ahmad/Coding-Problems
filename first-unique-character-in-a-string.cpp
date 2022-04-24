// https://leetcode.com/problems/first-unique-character-in-a-string

class Solution {
public:
    int firstUniqChar(string s) {
        //make an array of size 256 to keep count of the number
        int count[256];
        //initialize the array with -1, if the ith index contains -2 then the element is repeating
        // else if ith index contain value >= 0 then element is unique
        for(int i = 0; i < 256; i++)
            count[i] = -1;
      //looping through the string
        for(int i = 0; i < s.size(); i++){
          //if the s[i] is not already in [0...i - 1] part of the string then count[s[i]] will be -1, means it is its first occurence
            if(count[s[i]] == -1)
                count[s[i]] =  i;
          //else if already in [0...i-1] then store -2 at that index
            else
                count[s[i]] = -2;
        }
      //now loop through the count array and find the minimum non-repeating index
        int res = INT_MAX;
        for(int i = 0; i < 256; i++){
          //if count[i] >= 0 means it's non-repeating
            if(count[i] >= 0){
                res = min(res, count[i]);
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
