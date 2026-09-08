class Solution {
public:
    int countCommas(int n) {
        long long total = 0;
        long long threshold = 1000;
        
        while (n >= threshold) {
            total += (n - threshold + 1);
            threshold *= 1000;
        }
        
        return total;
    }
};