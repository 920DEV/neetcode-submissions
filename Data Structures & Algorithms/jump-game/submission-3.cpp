class Solution {
   public:
    bool canJump(vector<int>& nums) {
           int reach = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i > reach)
        {
            // How are we here if we cannot reach this index? just break.
            break;
        }
        reach = max(reach, nums[i] + i); 
    }

    return reach >= nums.size() - 1;
    }
};
