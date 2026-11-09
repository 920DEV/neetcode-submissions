class Solution {
   public:
    bool matchTarget(int a, int b, int c, vector<int> target) {
        if (a == target[0] && b == target[1] && c == target[2]) {
            return true;
        }
        return false;
    }

    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int a1 = INT_MIN;
        int b1 = INT_MIN;
        int c1 = INT_MIN;

        for (int i = 0; i < triplets.size(); i++) {
            if ((triplets[i][0] <= target[0]) && (triplets[i][1] <= target[1]) &&
                (triplets[i][2] <= target[2])) {
                a1 = max(a1, triplets[i][0]);
                b1 = max(b1, triplets[i][1]);
                c1 = max(c1, triplets[i][2]);
            }
            // if (triplets[i][1] == target[1]) {

            // }

            // if (triplets[i][2] == target[2]) {

            // }

            cout << " a ; " << a1 << " b : " << b1 << "c : " << c1 << endl;
            if (matchTarget(a1, b1, c1, target)) return true;

            // if ((triplets[i+1][0] <= target[0]) && (triplets[i+1][1] <= target[1]) &&
            //     (triplets[i+1][2] <= target[2])) {
            //     a1 = max(a1, triplets[i+1][0]);
            //     b1 = max(b1, triplets[i+1][1]);
            //     c1 = max(c1, triplets[i+1][2]);
            // }

            // if (triplets[i + 1][0] == target[0]) {
            //     a1 = max(triplets[i + 1][0], a1);
            // }
            // if (triplets[i + 1][1] == target[1]) {
            //     b1 = max(triplets[i + 1][1], b1);
            // }
            // if (triplets[i + 1][0] == target[2]) {
            //     c1 = max(triplets[i + 1][2], c1);
            // }

            // triplets[j][0] = a1;
            // triplets[j][1] = b1;
            // triplets[j][2] = c1;

            // if (matchTarget(a1, b1, c1, target)) return true;
        }
        return false;
    }
};
