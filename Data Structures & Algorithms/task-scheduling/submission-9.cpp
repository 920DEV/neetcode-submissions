class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;

        for(auto & task : tasks){
           
            freq[task]++;
        }

        priority_queue<int> maxFreq;

        for(auto &f : freq){
            maxFreq.push(f.second);
        }

        queue<pair<int, int>> coolDown;

        int time = 0;
        while(!maxFreq.empty() || !coolDown.empty()){
            time++;

            if(!coolDown.empty() && coolDown.front().second <= time){
                maxFreq.push(coolDown.front().first);
                coolDown.pop();
            }

            if(!maxFreq.empty()){
                int remaining = maxFreq.top()-1;
                maxFreq.pop();

                if(remaining >0){
                     coolDown.push({remaining,time + n +1});
                }
            }
        }

        return time;
    }
};
