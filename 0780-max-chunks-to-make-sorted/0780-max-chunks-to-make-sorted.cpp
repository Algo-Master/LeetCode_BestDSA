class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        int c = 0, mx = 0;
        for(int i = 0; i < arr.size(); i++) {
            mx = max(mx, arr[i]);
            if(mx == i) c++;
        }

        return c;
    }
};