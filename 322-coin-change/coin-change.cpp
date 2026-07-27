class Solution {
public:
       vector<int>dp;
    int solve(vector<int>& coins, int amount) {
        if(amount==0)
             return 0;
        if(amount<0)
            return INT_MAX;
        if(dp[amount] != -1)
             return dp[amount];
         int ans=INT_MAX;
        for(int coin:coins){
            int temp = solve(coins, amount - coin);
            if(temp!=INT_MAX){
              ans=min(ans,temp+1);
            }
        }
        return dp[amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int ans;
        dp.assign(amount+1,-1);
        ans=solve(coins,amount);
        return (ans == INT_MAX) ? -1 : ans;
    }    
};