// https://leetcode.com/problems/minimum-window-substring
//https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems
class Solution {
public:
    string minWindow(string s, string t) {
        size_t sSize = s.size(), tSize = t.size();
        if(!sSize || !tSize) return "";
        //start from [0, 0]
        int wL = 0, wR = 0, minLength = INT_MAX, lI, rI;
        unordered_map<char, int> map;
        //make hash-map for need
        for(char& c: t){
            if(map.find(c) == map.end())
                map.insert({c, 0});
            else map[c]++;
        }
        //hash-map for window
        unordered_map<char, int> window;
        //formed to check wheather the windows contain all unique characters of t
        int formed = 0, req = map.size();
        //outer-loop to expand the window
        while(wR < sSize){
            //if char in map then, insert that into window hash-map or increment if already exists
            if(map.find(s[wR]) != map.end()){
                if(window.find(s[wR]) != window.end())
                    window[s[wR]]++;
                else window.insert({s[wR], 0});
            }
            //if window contains the same number of characters as needed, the inc formed
            if(map.find(s[wR]) != map.end() && map[s[wR]] == window[s[wR]])
                formed++;
            //contract the window until it contains required quantity of characters
            while(wL <= wR && formed == req){
                //check and update length
                int l = wR - wL + 1;
                if(l < minLength) {
                    minLength = l;
                    lI = wL;
                    rI = wR;
                }
                //before moving to the next cell
                //check if the character is in the map
                // if yes, then dec it's count in window
                // if count of char becomes less than the need, dec formed
                if(map.find(s[wL]) != map.end()){
                    window[s[wL]]--;
                    if(window[s[wL]] < map[s[wL]]) formed--;
                }
                wL++;
            }
            wR++;
        }
        return minLength == INT_MAX ? "" : s.substr(lI, rI - lI + 1);
    }
};
