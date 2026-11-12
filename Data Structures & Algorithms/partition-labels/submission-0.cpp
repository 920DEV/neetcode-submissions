class Solution {
public:
    vector<int> partitionLabels(string s) {
        if(s == "") return {};

        unordered_map<int, int> maxCharIndex;

        for(int i = 0 ; i < s.length(); i++){
            maxCharIndex[s[i]] = i;
        }

        int lastIndex = 0 ; 
        int maxChr = s[0];
        vector<int> partitionSizeList;

        for(int i = 0 ;i< s.length();i++){

            if(maxCharIndex[s[i]] > maxCharIndex[maxChr]){
                maxChr = s[i];
                continue;
            }

            if(i == maxCharIndex[maxChr]){
                partitionSizeList.push_back(i-lastIndex + 1);
                lastIndex = i+1;
                maxChr = s[lastIndex];
            }
        }
        return partitionSizeList;
    }
};
