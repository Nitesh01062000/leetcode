class Solution {
public:
    int getScore(string str, int val, stack<char>&st, char first, char second ){
        int ans=0;
        for(int i=0;i<str.length();i++){
            if(st.empty()){
                st.push(str[i]);
            }else if(str[i]==second && st.top()==first){
                st.pop();
                ans+=val;
            }else{
                st.push(str[i]);
            }
        }
        return ans;
    }

    int maximumGain(string str, int x, int y) {
        int score=0;
        stack<char>st;
        if(x>y){
             string str2="";
            score+=getScore(str, x, st, 'a', 'b');
            while(!st.empty()){
                str2+=st.top();
                st.pop();
            }
            reverse(str2.begin(), str2.end());
            score+=getScore(str2, y, st, 'b','a');
        }else{
            string str2="";
            score+=getScore(str, y, st, 'b','a');
            while(!st.empty()){
                str2+=st.top();
                st.pop();
            }
            reverse(str2.begin(), str2.end());
            score+=getScore(str2, x, st, 'a', 'b');   
        }
        return score;
    }
};
