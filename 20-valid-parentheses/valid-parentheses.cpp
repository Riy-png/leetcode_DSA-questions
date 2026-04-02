class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> dict = {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'}
        };

        for(int i = 0; i < s.size(); i++) {
            if(dict.count(s[i])) {
                st.push(s[i]);  
            } else {
                if(st.empty() || dict[st.top()] != s[i]) {
                    return false;
                }
                st.pop();  
            }
        }

        return st.empty(); 
    }
};