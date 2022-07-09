class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        
         priority_queue<pair<int,int>> pq;      
         vector<int> dp(nums.size(),0);
		 
         for(int i=0;i<nums.size();i++)
         {
             while(!pq.empty() && pq.top().second<i-k)
                 pq.pop();
             
             dp[i]=nums[i]+(pq.empty()?0:pq.top().first);
             pq.push({dp[i],i});
         }
         return dp[nums.size()-1];
               
    }
};