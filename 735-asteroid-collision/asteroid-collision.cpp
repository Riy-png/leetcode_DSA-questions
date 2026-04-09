class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
       vector<int>st;
        for(int a:asteroids){
            bool collide= false;
            while(!st.empty() && st.back()>0 && a<0){
                if (abs(st.back()) < abs(a)){
                    st.pop_back();
                    continue;

                }else if(abs(st.back()) ==abs(a)){
                    st.pop_back();
                }
                collide = true;
                break;
            }
            if(!collide){
                st.push_back(a);
            }
        }
        return st;

    }
};