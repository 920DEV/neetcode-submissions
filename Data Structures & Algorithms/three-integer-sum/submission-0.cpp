class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;

        for(int i = 0;i< n ; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int j = i+1;
            int k = n-1;
            while(j<k){
                
                int sum = nums[i]+nums[j]+nums[k];

                if(sum>0){
                    k--;
                }
                else if(sum<0) j++;
                else
                {
                    vector<int>res;
                    res.push_back(nums[i]);
                    res.push_back(nums[j]);
                    res.push_back(nums[k]);
                    ans.push_back(res);
                    j++;
                    k--;
                    while(j<k && nums[j] == nums[j-1]) j++;
                    while(j<k && nums[k] == nums[k+1]) k--;
                }
                // if(!res.empty() && find(ans.begin(),ans.end(),res) == ans.end()){
                // }
            }
        }
        return ans;
        
    }
};