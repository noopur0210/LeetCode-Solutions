class Solution {
public:
    
    void solution(int index, int target, vector<int>& candidates, vector<int>& ds, vector<vector<int>>& res){
        
        if(index==candidates.size()){
            if(target==0){
                res.push_back(ds);
            }
            return;
        }
        
        if(candidates[index]<=target){
            ds.push_back(candidates[index]);
            solution(index, target-candidates[index], candidates, ds, res);
            ds.pop_back();
        }
        solution(index+1, target, candidates, ds, res);
            
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> res;
        solution(0, target, candidates, ds, res);
        return res;
    }
};