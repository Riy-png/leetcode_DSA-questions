class Solution {
public:
    bool isPalindrome(string &s, int i , int j) {
        if(i>=j){
            return true;
        }
        if(s[i]!=s[j]){
            return false;
        }
        return isPalindrome(s, i + 1, j - 1);
    }    
        bool isPalindrome( string &s){
             string temp = "";

        for (char ch : s) {
            if (isalnum(ch)) {
                temp += tolower(ch);
            }
        }

        return isPalindrome(temp, 0, temp.length() - 1);
    }
            
};