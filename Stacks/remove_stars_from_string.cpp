#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string removeStars(string s) {
        stack <char> st;
        int i=0;
        string res="";
        while(i<s.length()){
            if(s[i]=='*'){
                st.pop();
                i++;
            }
            else{
                st.push(s[i]);
                i++;
            }
        }

        while(st.size()>0){
            res+=st.top();
            st.pop();
        }

        reverse(res.begin(),res.end());
        return res;


    }
};

int main()
{
    string s="leet**cod*e";
    Solution s1;
    string res=s1.removeStars(s);
    cout<<res<<endl;
return 0;
}