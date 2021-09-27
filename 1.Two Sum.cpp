// Came up with a O(n2) approach using 2 for loops, reduced it to O(nlogn) by sorting the array and using 2 pointers. Finally came up with O(n) solution using hashmap.
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,pair<int,int>>hash_map;
        for(int i=0;i<nums.size();i++)
        {
            if(hash_map[target-nums[i]].first)
                return {hash_map[target-nums[i]].second,i};
            hash_map[nums[i]] = {1,i};
        }
        return {};
    }
};
