//https://leetcode.com/problems/two-sum
#include <map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hash;
        for(int i = 0; i < nums.size(); i++){
            int reqNumber = target - nums[i];
            auto find = hash.find(reqNumber);
            
            if(find != hash.end()){
                vector<int> result;
                result.push_back(i);
                result.push_back(find->second);
                return result;
            }
            else
                hash.insert({nums[i], i});
        }
        return vector<int>();
    }
};
