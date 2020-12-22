class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        // create dp array
        vector<int>dp(nums.size());
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.empty())
            {
                dp[i]=nums[i];
            }
            // remove elements when there are more than k elements in map
            else if(i>k)
            {
                mp[dp[i-k-1]]--;
                if(mp[dp[i-k-1]]==0)
                    mp.erase(dp[i-k-1]);
                dp[i]=(nums[i] + (*mp.rbegin()).first);
            }
            // add the largest value to the current number
            else
            {
                dp[i]=(nums[i] + (*mp.rbegin()).first);
            }
            mp[dp[i]]++;
        }
        return dp[nums.size()-1];
    }
};
