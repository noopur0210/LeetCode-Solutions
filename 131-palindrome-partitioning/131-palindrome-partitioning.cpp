class Solution {
public:
    
    bool isPalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start++]!=s[end--])
                return false;
        }
        return true;
    }
    
    void solution(int ind, string s, vector<string>& ds, vector<vector<string>>& res){
        if(ind==s.size()){
            res.push_back(ds);
            return;
        }
        
        for(int i=ind; i<s.size(); i++){
            if(isPalindrome(s, ind, i)){
                ds.push_back(s.substr(ind, i-ind+1));
                solution(i+1, s, ds, res);
                ds.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> ds;
        vector<vector<string>> res;
        solution(0,s,ds,res);
        return res;
    }
};