class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for(auto num : stones){
            maxHeap.push(num);
        }

        int i = 0;

        while(maxHeap.size()>=2){
            int x = maxHeap.top();
            maxHeap.pop();
            int y = maxHeap.top();
            maxHeap.pop();
            if(x!=y) {
                maxHeap.push(x-y);
            }
        }
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};
