//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        long ans=0;
        long mx=INT_MIN;
        int i=0;
        int j;
        for(j=0;j<K;j++){
            ans+=Arr[j];
            mx=max(mx,ans);
        }
        i++;
        while(j<N){
            ans=ans-Arr[i-1]+Arr[j];
            mx=max(mx,ans);
            i++;
            j++;
        }
        
        return mx;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends