class Solution {
public:
    bool predicate(vector<int>& nums, int k) {

        if(k == 1) return true;

        int bl1 = 0, bl2 = 0;

        for(int i = 0; i < k - 1; i++) {

            if(nums[i] >= nums[i+1]) bl1++;
        }
        for(int i = k; i < 2*k - 1; i++) {
            
            if(nums[i] >= nums[i+1]) bl2++;
        }

        if(bl1 == 0 && bl2 == 0) return true;

        for(int i = 2*k; i < nums.size(); i++) {

            if(nums[i - 1] >= nums[i]) bl2++;
            if(nums[i - k] >= nums[i - k + 1]) bl2--;

            if(nums[i - k - 1] >= nums[i - k]) bl1++;
            if(nums[i - 2*k] >= nums[i - 2*k + 1]) bl1--;

            if(bl1 == 0 && bl2 == 0) return true;
        }

        return false;
    }

    int maxIncreasingSubarrays(vector<int>& nums) {
        
        int l = 0, r = nums.size()/2 + 1;

        while (l + 1 < r) {

            int mid = (r + l)/2;

            if(predicate(nums, mid)) l = mid;
            else r = mid;
        }

        return l;
    }
};