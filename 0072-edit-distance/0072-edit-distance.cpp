class Solution {
public:
    int edit_dis(int i, int j, string &word1, string &word2, vector<vector<int>>& dp) {

        if(i < 0) return j + 1;
        if(j < 0) return i + 1;
        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i] == word2[j]) return dp[i][j] = edit_dis(i - 1, j - 1, word1, word2, dp);

        // Mimick Insert Operation
        int ins = 1 + edit_dis(i, j - 1, word1, word2, dp);
        // Mimick Delete Operation
        int del = 1 + edit_dis(i - 1, j, word1, word2, dp);
        // Mimick Replace Operation
        int rep = 1 + edit_dis(i - 1, j - 1, word1, word2, dp);

        return dp[i][j] = min(ins, min(del, rep));
    }
    int minDistance(string word1, string word2) {

        int n1 = word1.size(), n2 = word2.size();
        vector<vector<int>> dp(n1, vector<int> (n2, -1));

        return edit_dis(n1 - 1, n2 - 1, word1, word2, dp);
    }
};