class Solution {
public:
    void solve(vector<char>& s, int l ,  int r) {
        if(l>=r) return ;
           swap(s[l],s[r]);
           solve(s,l+1,r-1);
    }
    void reverseString(vector<char>& s) {
        int n =s.size();
         return solve(s,0,n-1);
    }    
};