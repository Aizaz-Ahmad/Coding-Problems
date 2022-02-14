//https://leetcode.com/problems/group-anagrams
// O(N * KlogK) - time
// O(NK)
//N size of input str, K - maximum length of string in strs
class NaiveSolution {

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        
        for(string str: strs){
            string copy = str;
            sort(str.begin(), str.end());
            auto find = groups.find(str);
            if(find == groups.end())
                groups.insert({str, {copy}});
            else
                (find->second).push_back(copy);
        }
        vector<vector<string>> result;
        for( const auto& [key, value] : groups ) 
            result.push_back(value);
        return result;
    }
};
