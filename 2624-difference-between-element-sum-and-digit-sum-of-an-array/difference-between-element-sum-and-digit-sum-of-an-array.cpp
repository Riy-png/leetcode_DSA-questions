class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
    int digits_sum=0;
    int element_sum=0;
    for(int num : nums){
    element_sum=element_sum+num;
    int x=num;
    while(x>0){
    digits_sum=digits_sum+x%10;
    x=x/10;
    }
    }
    return abs(element_sum - digits_sum);;
    
    }
};