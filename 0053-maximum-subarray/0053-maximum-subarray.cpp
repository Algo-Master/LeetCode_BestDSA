class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = nums[0];

        for(int i = 1; i < n; i++) {
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
        }

        int mx = -INT_MAX;
        for(auto &e: dp) mx = max(mx, e);

        return mx;
    }
};