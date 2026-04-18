class Solution {
public:
    int dp[1001][1001];

    int solve(int i, int j, string &str1, string &str2) {
        if (i == str1.size() || j == str2.size()) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (str1[i] == str2[j]) {
            return dp[i][j] = 1 + solve(i + 1, j + 1, str1, str2);
        }

        return dp[i][j] = max(solve(i + 1, j, str1, str2),
                              solve(i, j + 1, str1, str2));
    }

    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, text1, text2);
    }
};