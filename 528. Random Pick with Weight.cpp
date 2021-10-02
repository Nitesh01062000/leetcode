// First find cumulative frequencies of the weight array
// Now rand() will produce numbers in the desired range - 1
// increase the guess by one and find its index.


class Solution {
private:
    vector<int>cum_weights;
public:
    Solution(vector<int>& w) {
        for(int i=0;i<w.size();i++)
            cum_weights.push_back(w[i]+(i==0?0:cum_weights[i-1]));
    }
    
    int pickIndex() {
        int n = cum_weights.back();
        int guess = rand()%n;
        // cout<<guess<<endl;
        return lower_bound(cum_weights.begin(),cum_weights.end(),guess+1)-cum_weights.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
