class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l=*max_element(weights.begin(),weights.end()), r=accumulate(weights.begin(),weights.end(),0), ans=-1;
        while(l<=r){
            int requiredDays=1, load=0;
            int mid=l+(r-l)/2;
            for(int weight:weights){
                if(load+weight<=mid){
                    load+=weight;
                }else{
                    requiredDays++;
                    load=weight;
                }
            }
        
         if(requiredDays<=days){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
      }
        return ans;
    }
};
