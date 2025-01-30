class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Intuitive Solution
        /*
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
        */

        // Kadane Approach
        int n = nums.size();
        vector<vector<int>> dp(2, vector<int> (n, 0));
        dp[0][0] = dp[1][0] = nums[0];

        for(int i = 1; i < n; i++) {
            dp[0][i] = max(nums[i], max(dp[0][i-1]*nums[i], dp[1][i-1]*nums[i]));
            dp[1][i] = min(nums[i], min(dp[0][i-1]*nums[i], dp[1][i-1]*nums[i]));
        }

        int mx = INT_MIN;
        for(int i = 0; i < n; i++) {
            mx = max(mx, dp[0][i]);
            cout<<dp[0][i]<<" "<<dp[1][i]<<"\n";
        }

        return mx;
    }
};