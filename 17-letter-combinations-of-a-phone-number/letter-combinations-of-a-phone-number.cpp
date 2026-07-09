class Solution {
public:
    vector<string> ans;
    vector<string> mp = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void solve(int ind, string &digits, string curr) {
        if (ind == digits.size()) {
            ans.push_back(curr);
            return;
        }

        string letters = mp[digits[ind] - '0'];

        for (char ch : letters) {
            solve(ind + 1, digits, curr + ch);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        solve(0, digits, "");
        return ans;
    }
};