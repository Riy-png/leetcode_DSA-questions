class Solution {
public:
    bool canAliceWin(vector<int>& nums) {

        int singleSum = 0;
        int doubleSum = 0;

        for(int num : nums){

            if(num >= 0 && num <= 9){
                singleSum += num;
            }
            else if(num >= 10 && num <= 99){
                doubleSum += num;
            }
        }

        return singleSum != doubleSum;
    }
};