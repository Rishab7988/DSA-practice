#include<iostream>
#include<bits/stdc++.h>
using namespace std;


vector<int> slidingMaximum(vector<int> &A, int B) {
    deque<int>q;
    int i=0,j=0;
    vector<int>res;
    while(j<A.size()){
        while(!q.empty() && q.back()<A[j]) q.pop_back();
        q.push_back(A[j]);
        if(j-i+1<B) j++;
        else if(j-i+1==B){
            res.push_back(q.front());
            if(q.front()==A[i]) q.pop_front();
            i++;
            j++;
        }
    }
    return res;
}

void display(vector<int> v){
    for(auto it:v){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main()
{   
    vector<int> A={1,3,-1,-3,5,3,6,7};
    vector<int> ans=slidingMaximum(A,3);
    display(ans);
return 0;
}