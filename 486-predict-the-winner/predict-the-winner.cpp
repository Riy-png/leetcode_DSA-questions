class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        // 1D array to store the max score difference
        vector<int> dp(n, 0);
        
        // Traverse backwards to build the DP table bottom-up
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = nums[i];
            for (int j = i + 1; j < n; j++) {
                // Maximize current choice minus opponent's future optimal choice
                dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1]);
            }
        }
        
        // If the score difference is >= 0, Player 1 wins
        return dp[n - 1] >= 0;
    }
};