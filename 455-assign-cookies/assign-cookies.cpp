class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int greed=0;
        int sweets=0;

        while(sweets <s.size() && greed<g.size()){
            if(g[greed] <= s[sweets]){
                greed++;
            }
            sweets++;

        }
        return greed;
    }
};        