#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void get_permut(vector<int> v,vector<vector<int>> &ans,int index){
    if(index==v.size()){
        ans.push_back(v);
        return;
    }

    for(int i=index;i<v.size();i++){
        swap(v[index],v[i]);
        get_permut(v,ans,index+1);
        swap(v[index],v[i]);
    }
}

void display(vector<int> v){
    for(auto it:v){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> v={1,2,3};
    vector<vector<int>> ans;
    get_permut(v,ans,0);

    for(auto it: ans){
        display(it);
    }

return 0;
}