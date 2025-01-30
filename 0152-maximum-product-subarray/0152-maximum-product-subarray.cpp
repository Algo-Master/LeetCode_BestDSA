class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n = nums.size();
        int pre = 1, suf = 1, mx = INT_MIN;
        for(int i = 0; i < n; i++) {
            if(pre == 0) pre = 1;
            if(suf == 0) suf = 1;

            pre = pre * nums[i];
            suf = suf * nums[n - i - 1];

            mx = max(mx, max(pre, suf));
        }
        return mx;
        // vector<vector<int>> dp(2, vector<int> (n, -1));
        // dp[0][0] = dp[1][0] = nums[0];

        // for(int i = 1; i < n; i++) {
        //     dp[0][i] = max(dp[0][i]*nums[i], dp[1][i]*nums[i]);
        //     dp[1][i] = min(dp[0][i]*nums[i], dp[1][i]*nums[i]);
        // }

        // int mx = INT_MIN;
        // for(int i = 0; i < n; i++) {
        //     mx = max(mx, dp[0][i]);
        // }

        // return mx;
    }
};