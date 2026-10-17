class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>>q;
        vector<vector<int>>ans;
        for(int i = 0 ;i<points.size();i++){
            int x1 = points[i][0];
            int y1 = points[i][1];

            int distance = (x1*x1) + (y1*y1);

            if(q.size()<k){
                q.push({distance, {x1,y1}});
            }
            else if(q.top().first>distance){
                q.pop();
                 q.push({distance, {x1,y1}});
            }
        }

        while(!q.empty()){
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};
