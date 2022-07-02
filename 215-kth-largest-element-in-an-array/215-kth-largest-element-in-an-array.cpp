class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        
        int f = k-1;
        while(f>0){
            pq.pop();
            f--;
        }
        
        return pq.top();
    }
};