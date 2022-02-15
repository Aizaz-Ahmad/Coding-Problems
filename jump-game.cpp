// https://leetcode.com/problems/jump-game/
// https://leetcode.com/problems/jump-game/discuss/21121/C%2B%2B-elegant-solution-O(n)-time.
//https://leetcode.com/problems/jump-game/discuss/20917/Linear-and-simple-solution-in-C%2B%2B

class RecursiveSolution {
private: 
    bool canJump(vector<int>& nums, int start, int& lastPos){
        if(!nums[start]) return false;
        if(start + nums[start] >= lastPos) return true;
        if(!canJump(nums, start + nums[start], lastPos)){
            nums[start]--;
            return canJump(nums, start, lastPos);
        }
        return true;
    }
public:
    bool canJump(vector<int>& nums) {
        int lastPos = nums.size() - 1;
        if(nums.size() == 1) return true;
        nums.pop_back();
        return canJump(nums, 0, lastPos);
    }
};

bool canJump(int A[], int n) {
    int i = 0;
    for (int reach = 0; i < n && i <= reach; ++i)
        reach = max(i + A[i], reach);
    return i == n;
}
