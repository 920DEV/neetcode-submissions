class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!= t.length()) return false;

        unordered_map<char, int >mapi;
        for(int i = 0 ; i <s.length() ; i++){
            mapi[s[i]] += 1;
        }
        for(int i = 0 ; i <t.length();i++){
         int count =  --mapi[t[i]];
           if(count<0) return false;
        }
        return true;
    }
};
