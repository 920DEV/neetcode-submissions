class KthLargest {
public:

priority_queue<int, vector<int>, greater<int>> minHeap;
int khighest;
    KthLargest(int k, vector<int>& nums) {
        this->khighest = k;
        int i = 0;
        while(i<k && i<nums.size()){
            minHeap.push(nums[i]);
            i++;
        }
        while(i<nums.size()){
            if(nums[i]>minHeap.top()){
                minHeap.pop();
                minHeap.push(nums[i]);
            }
            i++;
        }
    }
    
    int add(int val) {

       if (minHeap.size() < khighest) {
    minHeap.push(val);
} else if (val > minHeap.top()) {
    minHeap.pop();
    minHeap.push(val);
}
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */