class Solution {
public:
    vector<int> dp;

    int rob(vector<int>& nums, int n) {
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = max(
            rob(nums, n - 1),
            nums[n - 1] + rob(nums, n - 2)
        );
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n + 1, -1);
        return rob(nums, n);
    }
};