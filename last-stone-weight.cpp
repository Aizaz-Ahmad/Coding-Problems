// https://leetcode.com/problems/last-stone-weight

class RecursiveSolution {
    int recursive(vector<int>& stones){
        if(stones.size() == 0) return 0;
        if(stones.size() == 1) return stones[0];
        if(stones[0] == stones[1])
            stones.erase(stones.begin(), stones.begin() + 2);
        else {
            stones[1] = abs(stones[0] - stones[1]);
            stones.erase(stones.begin());
        }
        return lastStoneWeight(stones);
    }
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(), stones.end(), greater<int>());
        return recursive(stones);
    }
};
