class Solution {
public:
    int minimumPushes(string word) {
        vector<int> counts(26, 0);
        for (char c : word) {
            counts[c - 'a']++;
        }
        
        sort(counts.rbegin(), counts.rend());
        
        int totalPushes = 0;
        for (int i = 0; i < 26; i++) {
            if (counts[i] == 0) {
                break;
            }
            int multiplier = (i / 8) + 1;
            totalPushes += counts[i] * multiplier;
        }
        
        return totalPushes;
    }
};
