class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 2) return n;
        int ans = 0;

        for(auto &a: points){
            unordered_map<double,int> m;
            double x1 = a[0], y1 = a[1];
            for(auto &b: points){   
                if(b == a) continue;  // Points with identical x and y are not considered to be distinct
                double x2 = b[0], y2 = b[1];
                double slope;
                if(x2-x1 == 0){
                    slope = INT_MAX; // slope is infinity for vertical line
                }else{
                    slope = (y2-y1)/(x2-x1);   
                }
                m[slope]++;
                ans = max(ans,m[slope]);
            }
        }
        return ans+1; //including point i
    }
};