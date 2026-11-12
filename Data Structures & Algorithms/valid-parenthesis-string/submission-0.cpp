class Solution {
public:
    bool checkValidString(string s) {
        if(s[0] == ')') return false;
        int minOpen = 0;
        int maxOpen = 0;

        for(int i = 0 ; i < s.length(); i++){
            if(s[i] == '(') {
                minOpen++;
                maxOpen++;
            }
            if(s[i] == ')'){
                minOpen--;
                maxOpen--;
            }
            if(s[i] == '*') {
                minOpen--;
                maxOpen++;
            }
            minOpen = max(minOpen, 0);
            if(maxOpen < 0 ) return false;
        }

        return minOpen == 0;
       
    }
};