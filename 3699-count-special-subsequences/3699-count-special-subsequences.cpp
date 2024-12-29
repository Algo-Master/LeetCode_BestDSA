#define ll long long int

class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {

        int n = nums.size();
        map<pair<int, int>, int> m;

        ll ans = 0;
        
        for(int r = 4; r < n - 2; r++) {
            for(int p = r - 4; p >= 0; p--) {
                int q = r - 2;

                int gcd = __gcd(nums[p], nums[q]);
                m[{nums[p]/gcd, nums[q]/gcd}]++;
            }
            for(int s = r + 2; s < n; s++) {
                int gcd = __gcd(nums[r], nums[s]);
                ans += m[{nums[s]/gcd, nums[r]/gcd}];
            }
        }

        return ans;
    }
};