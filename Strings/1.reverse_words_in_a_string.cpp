#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    bool isalpha(char a){
        if((a>='A' && a<='Z') || (a>='a' && a<='z') || (a>='0' && a<='9')){
            return true;
        }
        return false;
    }
    string reverseWords(string s) {
        vector<string> v;
        string temp="";

        for(int i=0;i<s.length();i++){
            if(isalpha(s[i])){
                temp+=s[i];
            }
            else if(s[i]==' ' && temp.size()>0){
                v.push_back(temp);
                temp="";
            }
        }
        if(temp.size()>0){
            v.push_back(temp);
        }
        string res="";
        for(int i=v.size()-1;i>=1;i--){
            res+=v[i];
            res+=" ";
        }
        res+=v[0];
        return res; 
    }
};


int main()
{
    string s="The sky is blue";
    Solution s1;
    string ans=s1.reverseWords(s);
    cout<<ans<<endl;
return 0;
}