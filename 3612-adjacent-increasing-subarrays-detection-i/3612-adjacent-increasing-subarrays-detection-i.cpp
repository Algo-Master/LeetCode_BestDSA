class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {

        int n = nums.size();

        if(n <= 2) return true;

        for(int i = 0; i <= n - 2*k; i++) {

            bool c1 = true, c2  = true;

            for(int j = i; j < i + k - 1; j++) {
                if(nums[j] >= nums[j+1]) c1 = false;
            }
            for(int j = i + k; j < i + 2*k - 1; j++) {
                if(nums[j] >= nums[j+1]) c2 = false;
            }

            if(c1 & c2) return true;
        }

        return false;
    }
};