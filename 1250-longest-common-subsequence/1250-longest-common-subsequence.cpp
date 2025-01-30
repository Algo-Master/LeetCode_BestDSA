class Solution {
public:
    int lcs(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {

        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int mx = 0;
        if(s1[i] == s2[j]) mx = 1 + lcs(i - 1, j - 1, s1, s2, dp);
        else {
            mx = lcs(i, j - 1, s1, s2, dp);
            mx = max(mx, lcs(i - 1, j, s1, s2, dp));
        }

        return dp[i][j] = mx;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return lcs(n1 - 1, n2 - 1, text1, text2, dp);
    }
};