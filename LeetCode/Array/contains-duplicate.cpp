//https://leetcode.com/problems/contains-duplicate/
// O(n)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> hash;
        for(int i = 0; i < nums.size(); i++){
            if(hash.find(nums[i]) == hash.end())
                hash.insert({nums[i], i});
            else
                return true;
        }
        return false;
    }
};
