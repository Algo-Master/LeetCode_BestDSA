class Solution {
public:
    int f(string s, int k) {

        unordered_map<int, int> m;
        int n = s.size(), count = 0;
        int l = 0, r = 0;

        while(r < n) {

            m[s[r]]++;

            while(m.size() > k) {

                m[s[l]]--;
                if(m[s[l]] == 0) m.erase(s[l]);
                l++;
            }

            count += r - l + 1;
            r++;
        }

        return count;
    }

    int numberOfSubstrings(string s) {
        
        return f(s, 3) - f(s, 2);
    }
};