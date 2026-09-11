class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int>unique_nums;
        int n = digits.size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j == i) continue;
                for (int k = 0; k < n; ++k) {
                    if (k == i || k == j) continue;

                    int hundreds = digits[i];
                    int tens = digits[j];
                    int ones = digits[k];

                    if (hundreds != 0 && ones % 2 == 0) {
                        unique_nums.insert(hundreds * 100 + tens * 10 + ones);
                    }
                }
            }
        }
        return unique_nums.size();
    }
};