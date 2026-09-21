class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        // Use long long for counts because total subarrays can exceed 2^31 - 1
        vector<long long> result(k, 0);
        unordered_map<int, long long> current_products;
        
        for (int num : nums) {
            unordered_map<int, long long> next_products;
            
            // 1. Extend existing subarrays
            for (const auto& [val, count] : current_products) {
                // Use 1LL to prevent integer overflow during multiplication
                int new_val = (1LL * val * num) % k;
                next_products[new_val] += count;
            }
            
            // 2. Start a new subarray at the current element
            int single_val = num % k;
            next_products[single_val] += 1;
            
            current_products = move(next_products);
            
            // 3. Add to total counts
            for (const auto& [val, count] : current_products) {
                result[val] += count;
            }
        }
        
        return result;
    }
};