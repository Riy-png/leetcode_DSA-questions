class Solution {
public:
     void solve(int target, vector<int>& candidates,int ind ,vector<int>& ds,vector<vector<int>> &ans ) {
        if(ind== candidates.size()){ // base condition
            if(target==0){ 
              return ans.push_back(ds);
            } 
           return ;
        }      

        if(candidates[ind]<=target){ // pick up the element
        ds.push_back(candidates[ind]);
        solve(target-candidates[ind],candidates,ind,ds,ans);
        ds.pop_back();  
        }
        solve(target,candidates,ind+1,ds,ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(target,candidates,0,ds,ans);
        return ans;
    }
};