class Solution {
public:
    int node_count = 0;
    vector<int> hotnode;
    vector<vector<int>> Trie;

    // Constructor to initialize the member variables
    Solution() : node_count(0), hotnode(1, 0), Trie(1, vector<int>(2, -1)) {}

    void insert(int n) {

        int cur = 0;
        for(int i = 30; i>=0; i--) {
            int cb = (n&(1<<i)) ? 1 : 0;
            if(Trie[cur][cb] == -1) {
                Trie[cur][cb] = ++node_count;
                Trie.push_back(vector<int> (2, -1));
                hotnode.push_back(0);
            }

            cur = Trie[cur][cb];
        }
        hotnode[cur]++;
    }

    int max_xor(int n) {

        int cur = 0, mxX = 0;

        for(int i = 30; i>=0; i--) {
            int cb = (n&(1<<i)) ? 1 : 0;

            if(Trie[cur][cb^1] != -1) {
                cur = Trie[cur][cb^1];
                mxX |= (1<<i);
            }
            else {
                cur = Trie[cur][cb];
            }
        }
        return mxX;
    }

    int findMaximumXOR(vector<int>& nums) {

        for(auto &e: nums) {
            insert(e);
        }

        int mxN = 0;

        for(auto &e: nums) mxN = max(mxN, max_xor(e));

        return mxN;
    }
};