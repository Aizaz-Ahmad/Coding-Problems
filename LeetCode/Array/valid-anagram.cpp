//https://leetcode.com/problems/valid-anagram/

// O(n) time - O(1) space

class WithoutHash {

public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        int chars[26];
        for(int i = 0; i < 26; i++) chars[i] = 0;
        for(int i = 0; i < s.length(); i++){
            chars[s[i] - 'a']++;
            chars[t[i] - 'a']--;
        }
        for(int a: chars)
            if(a) return false;
        return true;
    }
};

// O(n) time - O(n) space



class Solution {
private:
       unordered_map<char, int> createHashes(string s){
        unordered_map<char, int> chars;
        
        for(int i = 0; i < s.length(); i++){
            auto find = chars.find(s[i]);
            if(find == chars.end())
                chars.insert({s[i], 0});
            else
                find->second++;
        }
           return chars;
       } 
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char, int> sHash = createHashes(s);
        unordered_map<char, int> tHash = createHashes(t);
        for(auto itr = sHash.begin(); itr != sHash.end(); itr++){
            auto tfind = tHash.find(itr->first);
            if(tfind == tHash.end()) return false;
            if(itr->second != tfind->second) return false;
        }
        return true;
    }
};
