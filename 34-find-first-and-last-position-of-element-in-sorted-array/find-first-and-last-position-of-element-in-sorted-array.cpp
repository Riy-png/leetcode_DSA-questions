class Solution {
public:
    int FirstOccurrence(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1, ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(target==nums[mid]){
                ans=mid;
                r=mid-1;
            }else if(target>nums[mid]){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return ans;
    }
    int LastOccurrence(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1, ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(target==nums[mid]){
                ans=mid;
                l=mid+1;
            }else if(target>nums[mid]){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return ans;
    }
     vector<int> searchRange(vector<int>& nums, int target) {
        return {FirstOccurrence(nums, target),
                LastOccurrence(nums, target)};
    }
};