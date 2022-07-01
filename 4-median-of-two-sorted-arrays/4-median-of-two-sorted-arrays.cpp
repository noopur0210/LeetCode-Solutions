class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size()<nums1.size()) return findMedianSortedArrays(nums2, nums1);
        
        int n1 = nums1.size(), n2 = nums2.size();
        int low=0, high=n1;
        
        while(low<=high){
            int p1 = low + (high-low)/2;
            int p2 = (n1+n2+1)/2 - p1;
            
            int l1 = (p1==0) ? INT_MIN : nums1[p1-1];
            int l2 = (p2==0) ? INT_MIN : nums2[p2-1];
            int r1 = (p1==n1) ? INT_MAX : nums1[p1];
            int r2 = (p2==n2) ? INT_MAX : nums2[p2];
            
            if(l1<=r2 && l2<=r1){
                if((n1+n2)%2==0)
                    return (max(l1,l2)+min(r1,r2))/2.0;
                else
                    return max(l1,l2);
            }
            else if(l1>r2)
                high = p1-1;
            else
                low = p1+1;
        }
        
        return 0.0;
    }
};