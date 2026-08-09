class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffix_sum(n + 1, 0);
        
        for (int i = n - 1; i >= 0; --i) {
            suffix_sum[i] = suffix_sum[i + 1] + piles[i];
        }
        
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        
        for (int i = n - 1; i >= 0; --i) {
            for (int M = 1; M <= n; ++M) {
                if (i + 2 * M >= n) {
                    dp[i][M] = suffix_sum[i];
                } else {
                    for (int X = 1; X <= 2 * M; ++X) {
                        dp[i][M] = max(dp[i][M], suffix_sum[i] - dp[i + X][max(M, X)]);
                    }
                }
            }
        }
        
        return dp[0][1];
    }
};