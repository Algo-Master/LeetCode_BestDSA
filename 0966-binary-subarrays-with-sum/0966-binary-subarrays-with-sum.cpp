class Solution {
public:
    int f(vector<int> &nums, int goal) {

        if(goal < 0) return 0;

        int n = nums.size(), sum = 0, count = 0;
        int l = 0, r = 0;

        while(r < n) {

            sum += nums[r];

            while(sum>goal) {

                sum -= nums[l];
                l++;
            }
            count += r - l + 1;
            r++;
        }

        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        return f(nums, goal) - f(nums, goal - 1);
    }
};