class Solution {
public:
    bool isHappy(int n) {
         if(n==1) return true;
        unordered_map<int,int> mp;
       
        while(n){

            if(mp.find(n)!=mp.end()) return false;
            int x = n;
            int sum=0;
            while(x){
                int a = x%10;
                x/=10;
                sum+=a*a;
            }
            if(sum==1) return true;
            mp[n] = sum;
            n=sum;
        }
        return false;
    }
};