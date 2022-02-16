// https://leetcode.com/problems/insert-interval

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int start = intervals.size() - 1;
        while(start >= 0 && newInterval[0] <= intervals[start][0]) start--;
        intervals.insert(intervals.begin() + (start + 1> 0 ? start + 1 : 0), newInterval);
        vector<vector<int>> merged;
        
        for(auto interval: intervals){
            if(merged.empty() || merged.back()[1] < interval[0])
                merged.push_back(interval);
            else
                merged.back()[1] = max(merged.back()[1], interval[1]);
        }
        return merged;
    }
};
