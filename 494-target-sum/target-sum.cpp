class Solution {
public:
    int CountSum(vector<int>& nums, int target, int n,vector<vector<int>>& dp) {
        if (dp[n][target] != -1)
            return dp[n][target];
         if (n == 0) { // base case 
            if (target == 0 && nums[0] == 0)
                return 2; // include or exclude 0
            if (target == 0 || target == nums[0])
                return 1;
            return 0;
        }
        if(nums[n]<=target){
            return dp[n][target]= CountSum(nums, target-nums[n],n-1,dp)+CountSum(nums,target,n-1,dp);
        }else{
            return dp[n][target]= CountSum(nums,target,n-1,dp);
        }
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int Sum=0;
        for(auto x:nums){
            Sum+=x;
        }
        if (Sum<abs(target)||(Sum + target) % 2 != 0)
         return 0;
        int subsetSum = (Sum + target) / 2;
        vector<vector<int>> dp(n, vector<int>(subsetSum + 1, -1));
        return CountSum(nums,subsetSum,n-1,dp);
        
        
          // same as partition subset  & perfectsum 
    
    }
};