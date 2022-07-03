class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> f;
        
        for(int i=0; i<nums.size(); i++)
            f[nums[i]]++;
        
        
        priority_queue<pair<int, int>> pq;
        vector<int> res;
        
        for(auto it: f)
            pq.push({it.second, it.first});
        
        for(int i=0; i<k; i++){
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
        
    }
};