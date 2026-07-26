class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1, r=*max_element(piles.begin(),piles.end()), ans=-1;
        while(l<=r){
            long long hours=0;
            int mid=l+(r-l)/2;
            for(int pile : piles){
            hours += (pile + mid - 1) / mid;
            }
        
         if(hours<=h){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
      }
        return ans;
    }
};