class Solution {
public:
    int min_cost(vector<int>& cost, vector<int> &dp, int n) {
        if(n < 2) return cost[n];
        if(dp[n] != -1) return dp[n];
        return dp[n] = min(min_cost(cost, dp, n-1), min_cost(cost, dp, n-2)) + cost[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        return min(min_cost(cost, dp, n-1), min_cost(cost, dp, n-2));
    }
};