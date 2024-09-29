class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {

        sort(maximumHeight.begin(), maximumHeight.end());
        
        for(int i=0; i<maximumHeight.size(); i++) {
            
            if(i>=maximumHeight[i]) return -1LL;
        }

        long long int mx_sum = 0, cur = LLONG_MAX;

        for(int i = maximumHeight.size() - 1; i>=0; i--) {

            if(maximumHeight[i] < cur) {
                cur = maximumHeight[i];
                mx_sum += cur;
            }
            else {
                cur--;
                mx_sum += cur;
            }
        }

        return mx_sum;
    }
};
