// https://leetcode.com/problems/container-with-most-water
// O(n) time - O(1) space
class Solution {
public:
    int maxArea(vector<int>& height) {
        size_t size = height.size();
        int l = 0, r = size - 1;
        int maxArea = -1;
        while(l < r){
            int s = l;
            if(height[r] < height[s])
                s = r;
            int area = height[s] * (r - l);
            maxArea = max(area, maxArea);
            if(s == l)
                while(l < r && height[s] > height[l++]);
            else 
                while(l < r && height[s] < height[r--]);
            
        }
        
        return maxArea;
    }
};
