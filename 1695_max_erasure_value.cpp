class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        //prefix sum
        vector<int>pr(nums.size()+1,0);
        for(int i=0;i<nums.size();i++)
            pr[i+1]=(pr[i]+nums[i]);
        //storing index of each number
        unordered_map<int,int>mp;
        int ans=-1,curr=0,s=0;
        for(int i=0;i<nums.size();i++)
        {
            //if duplicate found
            if(mp[nums[i]]>0 && mp[nums[i]]>s)
            {
                ans=max(ans,curr);
                s=(mp[nums[i]]);
                curr=(pr[i+1]-pr[mp[nums[i]]]);
            }
            else
            {
                curr+=nums[i];
            }
            mp[nums[i]]=i+1;
        }
        ans=max(ans,curr);
        return ans;
    }
};
