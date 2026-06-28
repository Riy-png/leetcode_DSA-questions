class Solution {
public:
    vector<int> dp;

    int robHelper(vector<int>& nums, int n) {
      if(n==0) return 0;
      if(n==1) return nums[0];
      if(dp[n]!=-1) return dp[n];
      return dp[n]= max
      (robHelper(nums,n-1),
      nums[n-1] + robHelper(nums,n-2)
      );
    }
    int rob(vector<int>& nums){
        int n =nums.size();
        dp.assign(n+1,-1);
        return robHelper(nums,n);
    }  
};