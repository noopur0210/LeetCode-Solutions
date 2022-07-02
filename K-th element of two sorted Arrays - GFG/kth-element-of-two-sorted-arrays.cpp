// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
     int kthElement(int a[], int b[], int n, int m, int k)
    {
       if(n>m)
       return kthElement(b,a,m,n,k);
       
       int low=max(0,k-m),high=min(n,k),mid;
     
       
       while(low<=high){
           
                  mid= low+ (high-low)/2;
           
       int l1= mid==0 ? INT_MIN: a[mid-1];
       int l2= k-mid==0 ? INT_MIN : b[k-mid-1];
       int r1= mid==n ? INT_MAX : a[mid];
       int r2= k-mid==m ? INT_MAX : b[k-mid];
       
       
       if(r1>=l2 && r2>=l1)
       return max(l1,l2);
       else if(r2<l1 )
       high=mid-1;
       else
       low=mid+1;
       }
       
       return 1;
    }
};

// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  // } Driver Code Ends