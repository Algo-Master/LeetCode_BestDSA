class Solution {
public:
    int characterReplacement(string s, int k) {
        
        unordered_map<char,int> m;

        int n = s.size(), mxN = 0, local_max = 0;
        int l = 0, r = 0;

        while(r < n) {

            m[s[r]]++;
            if(m[s[r]] > local_max) local_max = m[s[r]];

            while((r - l + 1) - local_max > k) {

                m[s[l]]--;
                for(auto &[k, v]: m) local_max = max(local_max, v);

                l++;
            }

            mxN = max(mxN, r - l + 1);
            r++;
        }

        return mxN;
    }
};