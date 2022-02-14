// https://leetcode.com/problems/combination-sum/
// https://www.interviewbit.com/blog/combination-sum/
// https://www.geeksforgeeks.org/combinational-sum/

class Solution {
private:
    void findCombination(vector<int>& arr, int sum, vector<vector<int>>& res,vector<int>& r, int begin){
        if(sum == 0){
            res.push_back(r);
            return;
        }
        
        size_t size = arr.size();
        while(begin < size && sum - arr[begin] >= 0){
            r.push_back(arr[begin]);
            findCombination(arr, sum - arr[begin], res, r, begin);
            
            begin++;
            
            r.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        size_t size = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> r;
        findCombination(candidates, target, res, r, 0);
        return res;
    }
};
