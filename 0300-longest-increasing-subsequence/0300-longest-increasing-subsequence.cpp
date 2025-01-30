class Solution {
public:
    int longest_seq(int i, int prev, vector<vector<int>>& dp,
                    vector<int>& arr) {
        if (i < 0)
            return 0; // Base case

        if (dp[i][prev] != -1)
            return dp[i][prev]; // Memoization

        int tk = 0;
        if (arr[i] < arr[prev]) // Ensure valid comparison
            tk = 1 + longest_seq(i - 1, i, dp, arr);  // Take current element

        int nt_tk =
            longest_seq(i - 1, prev, dp, arr); // Don't take current element

        return dp[i][prev] = max(tk, nt_tk); // Memoize result
    }

    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();
        nums.push_back(INT_MAX);

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return longest_seq(n - 1, n, dp, nums);
    }
};