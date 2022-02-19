//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            //get mid element
            int mid = low + (high - low) / 2;
            //check if mid is not underflow and if previous element greater than the mid, 
            //then it is smallest in the array
            if (mid > low && nums[mid - 1] > nums[mid])
                return nums[mid];
            //check if mid is not overflown and if next element smaller than the present one,
            //if yes, then return the next element as it is after a larger number, 
            //so, it is the minimum number
            if (mid < high && nums[mid + 1] < nums[mid])
                return nums[mid + 1];
            //no element before the mid, then it is the smallest
            if (mid - 1 < 0) return nums[mid];
            //this means nums[mid] > nums[mid + 1] > nums[mid + 2], 
            //meaning minimum is in left half of mid
            if (nums[mid] < nums[high]) high = mid - 1;
            else low = mid + 1;
        }
        //when low == high, meaning only one element in the array left, that is the minimum
        return nums[low];
    }
};
