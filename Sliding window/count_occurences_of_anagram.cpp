//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    int cnt=0;
	    int i=0;
	    int j=0;
	    int k=pat.length();
	    
	    map<char,int> mp;
	    for(int p=0;p<k;p++){
	        mp[pat[p]]++;
	    }
	    
	    int num=mp.size();
	    
	    while(j<k){
	        if(mp.find(txt[j])!=mp.end()){
	            mp[txt[j]]--;
	            if(mp[txt[j]]==0){
	                num--;
	            }
	        }
	        j++;
	    }
	    
	    if(num==0){
	        cnt++;
	    }
	    
	    i++;
	    while(j<txt.length()){
	        if(mp.find(txt[i-1])!=mp.end()){
	            mp[txt[i-1]]++;
	            if(mp[txt[i-1]]==1){
	                num++;
	            }
	        }
	        
	        if(mp.find(txt[j])!=mp.end()){
	            mp[txt[j]]--;
	            if(mp[txt[j]]==0){
	                num--;
	            }
	        }
	        
	        if(num==0){
	            cnt++;
	        }
	        
	        j++;
	        i++;
	    }
	    return cnt;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends