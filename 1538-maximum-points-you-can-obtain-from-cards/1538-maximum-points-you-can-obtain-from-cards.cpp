class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n = cardPoints.size(), sum = 0;

        for(int i = n - k; i < n; i++) sum += cardPoints[i];

        int l = n - k;
        int max_sum = sum;

        for(int r = 0; r < k; r++) {

            sum += cardPoints[r] - cardPoints[l];

            max_sum = max(max_sum, sum);

            l++;
        }

        return max_sum;
    }
};