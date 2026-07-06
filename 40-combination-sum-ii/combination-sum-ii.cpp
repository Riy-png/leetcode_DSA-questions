class Solution {
public:
    vector<vector<int>> solve(vector<int>& candidates, int target, int idx) {

        if (target == 0)
            return {{}};

        if (idx == candidates.size() || target < 0)
            return {};

        vector<vector<int>> ans;

        // Pick current element
        auto take = solve(candidates, target - candidates[idx], idx + 1);
        for (auto &v : take) {
            v.push_back(candidates[idx]);
            ans.push_back(v);
        }

        // Skip all duplicates while not picking
        int next = idx + 1;
        while (next < candidates.size() &&
               candidates[next] == candidates[idx])
            next++;

        auto notTake = solve(candidates, target, next);
        ans.insert(ans.end(), notTake.begin(), notTake.end());

        return ans;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        return solve(candidates, target, 0);
    }
};