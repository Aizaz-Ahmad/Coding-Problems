// https://leetcode.com/problems/merge-intervals/

class InEfficientSolution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int start = 0;
        while(start < intervals.size() - 1){
            if(intervals[start][0] <= intervals[start + 1][1]
              && intervals[start][1] >= intervals[start + 1][0]){
                
                vector<int> par {intervals[start][0], intervals[start][1],
                                intervals[start + 1][0], intervals[start + 1][1]};
                
                intervals[start][0] = *min_element(par.begin(), par.end());
                intervals[start][1] = *max_element(par.begin(), par.end());
                
                intervals.erase(intervals.begin() + start + 1);
            }
            else start++;
        }
        return intervals;
    }
};
//O(nlogn) - time, O(logn) - space in sorting
class SortedSolution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        
        for(auto interval: intervals){
            //check if empty then insert, or no overlap
            if(merged.empty() || merged.back()[1] < interval[0])
                merged.push_back(interval);
            else
                merged.back()[1] = max(merged.back()[1], interval[1]);
        }
        return merged;
    }
};

//Check graph approach
