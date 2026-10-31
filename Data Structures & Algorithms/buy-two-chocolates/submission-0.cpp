class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int chocCount = 0;
        int initialMoney = money;
        priority_queue<int>qu;

        for(int& choc : prices){
            if(qu.size()<2){
                qu.push(choc);
            }
            else {
                if(qu.top() > choc){
                    qu.pop();
                    qu.push(choc);
                }
            }
        }

        while(!qu.empty()){
            if(qu.top() <= money){
                money -= qu.top();
            qu.pop();
            }
            else return initialMoney;
        }

        return money;
    }
};