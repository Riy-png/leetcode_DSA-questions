class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int>scores;
      for(int i=0;i<operations.size();i++){
        if(operations[i]=="C"){
            scores.pop_back();
        }else if(operations[i]=="D"){
            scores.push_back(2 * scores.back());
        
        }else if(operations[i] == "+") {
                int n = scores.size();
                scores.push_back(scores[n-1] + scores[n-2]);
                
        }else{
              scores.push_back(stoi(operations[i]));
        }
      } 
      int sum=0;
      for(int s : scores) {
            sum += s;
        }
        return sum;

    }
};