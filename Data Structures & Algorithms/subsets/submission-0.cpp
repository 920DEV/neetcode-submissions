class Solution {
public:

    void findSubSets(int index, vector<vector<int>>&ans, vector<int>&nums, vector<int> & current){

        if(index == nums.size()) {
            ans.push_back(current);
            return;
        }

        current.push_back(nums[index]);
        findSubSets(index+1, ans, nums, current);
        current.pop_back();
        findSubSets(index+1, ans, nums, current);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        findSubSets(0,ans, nums, current);

        return ans;
    }
};
