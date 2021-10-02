// First find the largest occurence of a charecter and place all charecters in ans string.
// Then place each remaining charecter at alternate places until done.
// Check if problem condition holds true or not.

class Solution {
public:
    string reorganizeString(string s) {
        map<char,int>mp;
        for(auto i:s)
            mp[i]++;
        string ans="";
        int x=0;
        int pos=1;
        while(1)
        {
            if(mp.empty())
                break;
            char c;
            int freq=0;
            for(auto i:mp)
            {
                if(i.second>freq)
                {
                    freq = i.second;
                    c = i.first;
                }
            }
            // cout<<c<<" "<<freq<<endl;
            if(x==0)
            {
                while(freq--)
                    ans+=c;
                // cout<<ans<<endl;
            }
            while(freq && x)
            {
                if(pos>ans.size())
                    pos=1;
                ans.insert(ans.begin()+pos,c);
                // cout<<ans<<endl;
                freq--;
                pos+=2;
            }
            mp.erase(c);
            x++;
        }
        if(ans.size()==1)
            return ans;
        for(int i=1;i<ans.size();i++)
        {
            if(ans[i]==ans[i-1])
                return "";
        }
        return ans;
    }
};
