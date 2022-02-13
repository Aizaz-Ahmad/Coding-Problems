// https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution {
private:
  //https://www.geeksforgeeks.org/find-minimum-element-in-a-sorted-and-rotated-array/
    int indexOfMinEle(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (mid > low && nums[mid - 1] > nums[mid])
                return mid;
            if (mid < high && nums[mid + 1] < nums[mid])
                return mid + 1;
            if (mid - 1 < 0) return mid;
            //this means nums[mid] > nums[mid + 1] > nums[mid + 2], 
            //meaning minimum is in left half of mid
            if (nums[mid] < nums[high]) high = mid - 1;
            else low = mid + 1;
        }
        cout << low <<  "\n";
        return low;
    }
public:
    int search(vector<int>& nums, int target) {
        size_t size = nums.size();
        int low = 0, high = size - 1;
        int minIndex = indexOfMinEle(nums);
        while (low <= high) {
            int mid = (high + low) / 2;
            int realmid = (mid + minIndex) % size;
            int ele = nums[realmid];
            if (ele == target) 
                return realmid;
            else if (ele < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};
