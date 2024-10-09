class Solution {
public:
    int solver(int i, bool buy, vector<int> &prices, vector<vector<int>> &dp) {

        if(i<0) {
            if(buy) return -3e4;
            return 0;
        }

        if(dp[i][buy] != -1) return dp[i][buy];

        int profit = 0;
        if(buy) {
            int take = solver(i-1, 0, prices, dp) - prices[i];
            int n_take = solver(i-1, 1, prices, dp);

            profit = max(take, n_take);
        } else {
            int take = solver(i-1, 1, prices, dp) + prices[i];
            int n_take = solver(i-1, 0, prices, dp);

            profit = max(take, n_take);
        }
        
        dp[i][buy] = profit;
        return profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solver(n - 1, 0, prices, dp);
    }
};