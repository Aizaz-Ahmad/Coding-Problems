// https://leetcode.com/problems/maximum-subarray/
//https://leetcode.com/problems/maximum-subarray/discuss/1470547/C%2B%2B-Easy-and-Clean-Solution-or-Fastest%3A-0ms-or-All-Methods-or-Follow-Ups-or-Detailed-Explanation
// O(n) time - O(1) space
//https://leetcode.com/problems/maximum-subarray/discuss/1595097/JAVA-or-Kadane's-Algorithm-or-Explanation-Using-Image
class IterativeSolution {
public:
    int maxSubArray(vector<int>& nums) {
        size_t size = nums.size();
        if(size == 1) return nums[0];
       
        int sum = 0; int maxSum = INT_MIN;
        for(int i = 0; i < size; i++){
            sum += nums[i];
            maxSum = max(maxSum, sum);
            if(sum < 0) sum = 0;
        }
        return maxSum;
    }
};

//https://leetcode.com/problems/maximum-subarray/discuss/20193/DP-solution-and-some-thoughts

class DPSolution {
public:
    int maxSubArray(vector<int>& nums) {
        size_t size = nums.size();
        if(size == 1) return nums[0];
        int _max = nums[0];
        int prevMax = nums[0];
        
        for(int i = 1; i < size; i++){
            prevMax = nums[i] + (prevMax > 0 ? prevMax : 0);
            _max = max(_max, prevMax);
        }
        return _max;
        
    }
};
