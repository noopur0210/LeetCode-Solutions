class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        if(nums.size()<3 || nums[0]>0) return res;
        
        for(int i=0; i<nums.size()-2; i++){
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){
                int j=i+1, k=nums.size()-1, sum = 0-nums[i];
                while(j<k){
                    if(nums[j]+nums[k] == sum){
                        vector<int> temp{nums[i], nums[j], nums[k]};
                        res.push_back(temp);
                        
                        while(j<k && nums[j]==nums[j+1]) j++;
                        while(j<k && nums[k]==nums[k-1]) k--;
                    
                        j++; k--;
                    }
                    
                    
                    else if(nums[j]+nums[k] > sum) k--;
                    else j++;
                     
                }
            }
        }
        return res;
    }
};