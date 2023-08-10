//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 
        vector<long long > ans;
        int i=0;
        int j=0;
        int flag=0;
        queue<int> neg;
        
        while(j<K){
            if(A[j]<0){
                neg.push(A[j]);
                flag=1;
            }
            j++;
        }
        if(flag==1){
            ans.push_back(neg.front());   
        }
        else{
            ans.push_back(0);
        }
        
        i++;
        while(j<N){
            if(neg.size()>0 && neg.front()==A[i-1]){
                neg.pop();
            }
            
            if(A[j]<0){
                neg.push(A[j]);
            }
            if(neg.size()==0){
                ans.push_back(0);
            }
            else{
                ans.push_back(neg.front());
            }
            i++;
            j++;
        }
        
        return ans;
        
                                                 
 }