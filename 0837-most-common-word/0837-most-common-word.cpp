class Solution {
public:
    bool is_present(string word, vector<string>& banned) {
        for(auto &e: banned) {
            if(word == e) return true;
        }
        return false;
    }
    string mostCommonWord(string paragraph, vector<string>& banned) {

        // Normalize the string

        for(auto &ch: paragraph) {
            if(!isalpha(ch)) ch = ' ';
            ch = tolower(ch);
        }
        
        map<string, int> words_map;

        stringstream s(paragraph);
        string word, most_common_word;

        while(s >> word) {
            words_map[word]++;
        }

        int max_count = 0;

        for(auto &[word, count]: words_map) {
            if(max_count < count && !is_present(word, banned)) {
                max_count = count;
                most_common_word = word;
            }
        }

        return most_common_word;
    }
};