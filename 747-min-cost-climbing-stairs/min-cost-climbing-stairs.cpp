class Solution {
public:
       vector<int> dp;
    int Solve(vector<int>& cost, int n) {

        if(n==0) return 0;
        if(n==1) return 0; 
        if (dp[n] != -1)
            return dp[n];
         return dp[n]= min(Solve(cost,n-1)+cost[n-1], Solve(cost,n-2) + cost[n-2] );
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n =cost.size();
        dp.assign(n+1,-1);
        return Solve(cost,n);
    }


};