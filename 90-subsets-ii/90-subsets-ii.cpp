class Solution {
public:
    
    void solution(int ind, vector<int>& nums, vector<int>& subsets, vector<vector<int>>& res){
        res.push_back(subsets);
         for (int i = ind; i < nums.size(); i++) {
            if (i != ind && nums[i] == nums[i - 1]) continue;
            subsets.push_back(nums[i]);
            solution(i + 1, nums, subsets, res);
            subsets.pop_back();
         }
    }
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> subsets;
        
        solution(0, nums, subsets, res);
        return res;
    }
};