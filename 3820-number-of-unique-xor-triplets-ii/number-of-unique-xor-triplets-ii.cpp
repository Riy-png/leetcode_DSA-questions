

class Solution {
public:
    int uniqueXorTriplets(std::vector<int>& nums) {
        int n = nums.size();
        
        
        int max_val = 0;
        for (int num : nums) {
            max_val = max(max_val, num);
        }
        
        int T = 1;
        while (T <= max_val) {
            T <<= 1;
        }
        
        int limit = max(T, 2048);
        
        vector<bool> s1(limit, false);
        vector<bool> s2(limit, false);
        
        // Pass 1: Precompute all pair XORs (i <= j)
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                s1[nums[i] ^ nums[j]] = true;
            }
        }
        
        // Pass 2: Combine precomputed pair XORs with each element in nums (k >= j)
        for (int i = 0; i < limit; i++) {
            if (s1[i]) {
                for (int num : nums) {
                    s2[i ^ num] = true;
                }
            }
        }
        int unique_count = 0;
        for (int i = 0; i < limit; i++) {
            if (s2[i]) {
                unique_count++;
            }
        }
        
        return unique_count;
    }
};
    