// https://leetcode.com/problems/jump-game/

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
