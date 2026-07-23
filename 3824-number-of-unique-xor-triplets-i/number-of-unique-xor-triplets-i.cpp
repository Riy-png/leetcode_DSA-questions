

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        
        // Find the bit length of n
        int bit_length = 0;
        int temp = n;
        while (temp > 0) {
            bit_length++;
            temp >>= 1;
        }
        
        return 1 << bit_length;
    }
};
