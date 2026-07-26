class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=0 , tank=0 , total=0;
        for(int i=0;i<gas.size();i++){
        int profit = gas[i]-cost[i];
        tank+=profit;
        total+=profit;
        if(tank<0){
            start=i+1;
            tank=0;
        }
        }
         if(total < 0)
            return -1;
        
        return start;
    }
};