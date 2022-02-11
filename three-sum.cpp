//https://leetcode.com/problems/3sum
// O(n * 2) - time
class Solution {
private:
    bool isInHashMap(unordered_map<int, int>& hash, int key) {
        auto it = hash.find(key);
        return it != hash.end();
    }
    bool insertIfKeyNotInHash(unordered_map<int, int>& hash, int key, pair<int, int> p) {
        if (!isInHashMap(hash, key)) {
            hash.insert(p);
            return true;
        }
        return false;
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        size_t size = nums.size();
        if (size <=2) return vector<vector<int>>();
        unordered_map<int, int> solution;
        vector<vector<int>> result;
        for (int k = size - 1; k >= 0; k--) {
           if (isInHashMap(solution, nums[k])) continue;
            int target = -nums[k];
            unordered_map<int, int> numbers;
            for (int i = 0; i < size; i++) {
                if (i != k && !insertIfKeyNotInHash(numbers, target - nums[i], { nums[i], i })) {
                    result.push_back({nums[k], target - nums[i], nums[i] });
                    
                    insertIfKeyNotInHash(solution,nums[i], { nums[i], 1 });
                    insertIfKeyNotInHash(solution,target - nums[i], { target - nums[i], 1 });
                    insertIfKeyNotInHash(solution, nums[k], { nums[k], 1 });
                }
            }

        }

        return result;
    }
};
