class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        
        // If needle is longer than haystack, it can't be inside it
        if (m > n) {
            return -1;
        }
        
        // Loop through the haystack, stopping when the remaining characters 
        // are fewer than the needle's length
        for (int i = 0; i <= n - m; i++) {
            int j = 0;
            
            // Check if characters match one by one
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }
            
            // If we matched all characters in the needle, we found it
            if (j == m) {
                return i;
            }
        }
        
        return -1;
    }
};