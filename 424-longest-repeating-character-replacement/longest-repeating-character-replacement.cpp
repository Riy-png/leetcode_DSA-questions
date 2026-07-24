class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0, maxfreq=0, ans=0 , r=0;
        unordered_map<int,int> freq;
        for(int r=0;r<s.size();r++){
            freq[s[r]]++;
            maxfreq=max(maxfreq,freq[s[r]]);

        
          while((r-l+1)-maxfreq>k){
            freq[s[l]]--;
            l++;
          }
            ans =max(ans,r-l+1);
          
        }
        return ans;
    }
};