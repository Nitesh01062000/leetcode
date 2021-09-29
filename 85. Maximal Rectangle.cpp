// First approached with prefix in each row, TC - O(N*M*N). 
// Then maximum area of a histogram, TC - O(N*M).
  
class Solution {
public:
    int max_area_building(vector<int>&heights)
    {
        int n = heights.size();
        stack<int>st;
        vector<int>max_left(n);
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(st.empty())
                max_left[i]=-1;
            else
                max_left[i]=st.top();
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        vector<int>max_right(n);
        for(int i = n-1;i>=0;i--)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(st.empty())
                max_right[i]=n;
            else
                max_right[i]=st.top();
            st.push(i);
        }
        int max_area = 0;
        for(int i=0;i<n;i++)
        {
            // cout<<max_left[i]<<" "<<max_right[i]<<endl;
            max_area = max(max_area,heights[i]*(max_right[i]-max_left[i]-1));
        }
        return max_area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>heights(m,0);
        int max_area = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='0')
                    heights[j]=0;
                else
                    heights[j]++;
            }
            // for(auto i:heights)
            //     cout<<i<<" ";
            // cout<<endl;
            // cout<<max_area_building(heights)<<endl;
            max_area = max(max_area,max_area_building(heights));
        }
        return max_area;
    }
};
