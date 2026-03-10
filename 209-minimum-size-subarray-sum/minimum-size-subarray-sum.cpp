class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int j=0;
        int min_sum=INT_MAX;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        
        while(sum>=target){
            min_sum=min(min_sum,i-j+1);
            sum-=nums[j];
            j++;
        }
    }  
    if(min_sum==INT_MAX)
     return 0;

    return min_sum; 
    }
    
};