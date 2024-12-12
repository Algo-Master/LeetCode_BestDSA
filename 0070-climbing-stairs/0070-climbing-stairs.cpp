class Solution {
public:
    int count_ways(vector<int> &dp, int n) {
        if(n == 0) return 1;
        else if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];

        return dp[n] = count_ways(dp, n-1) + count_ways(dp, n-2);
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return count_ways(dp, n);
    }
};