// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:

    void fun(vector<int> arr, vector<int> &subs, int N, int sum){
        if(N==0){
            subs.push_back(sum);
            return;
        }
        
        fun(arr, subs, N-1, sum);
        fun(arr, subs, N-1, sum+arr[N-1]);
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> subs;
        fun(arr, subs, N, 0);
        return subs;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends