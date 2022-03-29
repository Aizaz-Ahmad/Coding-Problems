// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0, right = 0;
        int k = 0;
        size_t size = nums.size();
        while(left < size && right < size){
            while(right < size && nums[left] == nums[right]) right++;
            nums[k++] = nums[left];
            left = right;
        }
        return k;
    }
};
