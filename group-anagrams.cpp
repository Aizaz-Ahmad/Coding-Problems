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

class CountingSortSolution {
private:
    void counting_sort(string& str){
        vector<int> lower (26, 0);
        for(char& a: str)
            lower[a - 'a']++;
        for(int i = 1; i < 26;i++)
            lower[i] += lower[i - 1];
        string copy = str;
        int size = str.size();
        for(int i = size - 1; i >=0; i--){
            copy[lower[str[i] - 'a'] - 1] = str[i];
            lower[str[i] - 'a']--;
        }
        str = copy;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        
        for(string& str: strs){
            string copy = str;
            counting_sort(str);
            auto find = groups.find(str);
            if(find == groups.end())
                groups.insert({str, {copy}});
            else
                (find->second).push_back(copy);
        }
        vector<vector<string>> result;
        for( const auto& [key, value] : groups) 
            result.push_back(value);
        return result;
    }
};
