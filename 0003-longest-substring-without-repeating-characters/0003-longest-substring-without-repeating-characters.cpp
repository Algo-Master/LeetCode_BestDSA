class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char,int> m;

        int mxN = 0, n = s.size();
        int l = 0, r = 0;

        while(r<n) {

            m[s[r]]++;

            while(m[s[r]] > 1) {

                m[s[l]]--;
                l++;
            }

            mxN = max(mxN, r - l + 1);
            r++;
        }

        return mxN;
    }
};