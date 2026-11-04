class Solution {
public:
    int jump(vector<int>& nums) {
        int minStep =0 ;
        int count = 0;

    int currentEnd = 0;

        for(int i = 0 ;i<nums.size()-1;i++){
            if(minStep < i+nums[i]){
                minStep = i+ nums[i];
            }
            if(i == currentEnd) {
                count++;
                currentEnd = minStep;
            }
        }

        return count;
    }
};