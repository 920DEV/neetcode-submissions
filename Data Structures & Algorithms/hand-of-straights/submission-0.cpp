class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0 ) return false;

        map<int,int>frequency;

        for(auto card : hand){
            frequency[card]++;
        }

        while(frequency.size() != 0 ){
         int count = frequency.begin()->second;
         int smallest = frequency.begin()->first;

            for(int j = 0 ; j<groupSize; j++){
                int card = smallest + j;

                if(frequency[card] < 0 ) return false;

                frequency[card] -= count;

                if(frequency[card] == 0 ){
                    frequency.erase(card);
                }
            }
        }

        return true;
    }
};
