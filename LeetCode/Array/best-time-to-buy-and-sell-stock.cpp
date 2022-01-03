// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

//Space Complexity same for both - O(1)

//Approach 1 - Brute Force - O(n * 2)
class BruteForce {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int sIdx, bIdx;
        size_t size = prices.size();
        for(int i = 0; i < size; i++){
            for(int j = i + 1; j < size; j++){
                int profit = prices[j] - prices[i];
                if(profit > max){
                    max = profit;
                }
            }
        }
        return max;
    }
};

// Approach 2 - One Pass - O(n)
class OnePass {
public:
    int maxProfit(vector<int>& prices) {
       int minPrice = INT_MAX;
        int maxProfit = 0;
        size_t size = prices.size();
    
        for(int i = 0; i < size; i++){
            if(prices[i] < minPrice)
                minPrice = prices[i];
            if(prices[i] - minPrice > maxProfit)
                maxProfit = prices[i] - minPrice;
        }
        return maxProfit;
    }
};
