class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int profitSoFar = 0;
        int lastSmallest  = 0;
        for(int i = 1 ;i < prices.size();i++){
           if(prices[i] - prices[lastSmallest]> 0){
              profit = std::max(prices[i]-prices[lastSmallest],profit);
              std::cout << profit << " profit " << std::endl;
           } else {
            lastSmallest = i;
           }
        }
        return profit;
    }
};
