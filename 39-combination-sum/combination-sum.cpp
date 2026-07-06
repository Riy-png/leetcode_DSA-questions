class Solution {
public:
     vector<vector<int>> solve(int target, vector<int>& candidates,int idx) {
           if (target == 0)
            return {{}} ;

        if (idx == candidates.size() || target < 0)
            return {} ;

        vector<vector<int>> ans;

        // Pick current element
       auto take= solve(target - candidates[idx],candidates, idx );
        for (auto &v : take) {
            v.push_back(candidates[idx]);
            ans.push_back(v);
        }

        // Skip all duplicates while not picking
        int next = idx + 1;

        auto notTake=solve(target,candidates, next);
        ans.insert(ans.end(), notTake.begin(), notTake.end());

        return ans;   
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         sort(candidates.begin(), candidates.end());
        return solve(target,candidates,0);
    }
};