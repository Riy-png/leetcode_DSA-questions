class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int initial_ones = 0;
        vector<int> zero_blocks;
        int current_zeros = 0;

        // Traverse the string to count initial '1's and collect lengths of '0' blocks
        for (char c : s) {
            if (c == '1') {
                initial_ones++;
                if (current_zeros > 0) {
                    zero_blocks.push_back(current_zeros);
                    current_zeros = 0;
                }
            } else {
                current_zeros++;
            }
        }
        
        // Catch any trailing block of '0's at the end of the string
        if (current_zeros > 0) {
            zero_blocks.push_back(current_zeros);
        }

        // If there are fewer than 2 blocks of '0's, a valid trade isn't possible
        if (zero_blocks.size() < 2) {
            return initial_ones;
        }

        // Find the maximum sum of two adjacent '0' blocks
        int max_gain = 0;
        for (size_t i = 0; i < zero_blocks.size() - 1; ++i) {
            int gain = zero_blocks[i] + zero_blocks[i + 1];
            if (gain > max_gain) {
                max_gain = gain;
            }
        }

        return initial_ones + max_gain;
    }
};