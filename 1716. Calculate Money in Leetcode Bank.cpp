class Solution {
public:
    int totalMoney(int n) {
        int ans=0;
        int curr=1;
        while(n)
        {
            for(int i=curr;i<=min(curr+n-1,6+curr);i++)
                ans+=i;
            curr++;
            n-=min(7,n);
        }
        return ans;
    }
};
