class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int mxN = 0, count_zero = 0, n = nums.size();
        int l = 0, r = 0;

        while(r<n) {

            if(nums[r] == 0) count_zero++;

            while(count_zero > k) {

                if(nums[l] == 0) count_zero--;
                l++;
            }

            mxN = max(mxN, r - l + 1);

            r++;
        }

        return mxN;
    }
};