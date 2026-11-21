class Solution {
public:
    bool canEat(vector<int> &piles, int k , int h){
        int count = 0;

        for(int& pile: piles){
            count += ceil(double(pile)/ double(k));
            if(count > h ) return false;
        }
        return true;

    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(canEat(piles,mid,h)){
                ans = min(ans,mid);
                high = mid-1;
            }
            else {
                low = mid +1;
            }
        }

        return low;
    }
};
