class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends == 1) return word;
        
        char mx = 'a';
        int n = word.size();
        int ext = n - numFriends + 1;
        vector<string> ans;

        for(int i = 0; i < n; i++) {
            mx = max(mx, word[i]);
        }

        for(int i = 0; i < n; i++) {
            if(word[i] == mx) {
                int c = 0;
                string s = "";
                for(int j = i; j < n; j++) {
                    if(c < ext) {
                        s += word[j];
                        c++;
                    } else break;
                }
                ans.push_back(s);
            }
        }

        sort(ans.begin(), ans.end(), greater<>());
        return ans[0];
    }
};