class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int n = nums.size(), sum = nums[0];

        vector<int> dp_mn(n, -1);
        vector<int> dp_mx(n, -1);

        dp_mx[0] = dp_mn[0] = nums[0];

        for(int i = 1; i < n; i++) {
            dp_mx[i] = max(dp_mx[i-1] + nums[i], nums[i]);
            dp_mn[i] = min(dp_mn[i-1] + nums[i], nums[i]);
            sum += nums[i];
        }

        int mx = INT_MIN, mn = INT_MAX;
        for(int i = 0; i < n; i++) {
            mx = max(mx, dp_mx[i]);
            mn = min(mn, dp_mn[i]);
        } cout<<mx<<" "<<mn<<"\n";
        return sum == mn? mx : max(mx, sum - mn);
    }
};