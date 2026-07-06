class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& nums, int n, vector<int>& currentElement) {
        if (n == nums.size()) {
            ans.push_back(currentElement);
            return;
        }
        sort(nums.begin(),nums.end());
        currentElement.push_back(nums[n]);
        solve(nums, n + 1, currentElement);

        currentElement.pop_back();
        while (n + 1 < nums.size() && nums[n] == nums[n + 1]) {
            n++;
        }
        solve(nums, n + 1, currentElement);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> currentElement;
        solve(nums, 0, currentElement);
        return ans;
    }
};