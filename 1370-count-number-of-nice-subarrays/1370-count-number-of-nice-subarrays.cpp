class Solution {
public:
    int f(vector<int> &nums, int k) {

        int n = nums.size(), odd = 0, count = 0;
        int l = 0, r = 0;

        while(r < n) {

            if((nums[r]&1) == 1) odd++;

            while(odd > k) {

                if((nums[l]&1) == 1) odd--;
                l++;
            }

            count += r - l + 1;
            r++;
        }

        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        
        return f(nums, k) - f(nums, k - 1);
    }
};