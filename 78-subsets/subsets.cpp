class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& nums, int n, vector<int>& currentElement) {
        if (n == nums.size()) {
            ans.push_back(currentElement);
            return;
        }

        currentElement.push_back(nums[n]);
        solve(nums, n + 1, currentElement);

        currentElement.pop_back();
        solve(nums, n + 1, currentElement);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> currentElement;
        solve(nums, 0, currentElement);
        return ans;
    }
};