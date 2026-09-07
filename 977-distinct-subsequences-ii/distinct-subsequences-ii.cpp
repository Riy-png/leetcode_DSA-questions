class Solution {
public:
    int distinctSubseqII(string s) {
        long long mod = 1e9 + 7;
        vector<long long> dp(26, 0);
        long long total_subseqs = 0;
        
        for (char ch : s) {
            int idx = ch - 'a';
            long long new_subseqs = (total_subseqs + 1 - dp[idx] + mod) % mod;
            total_subseqs = (total_subseqs + new_subseqs) % mod;
            dp[idx] = (dp[idx] + new_subseqs) % mod;
        }
        
        return total_subseqs;
    }
};