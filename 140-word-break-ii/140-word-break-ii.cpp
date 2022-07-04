class Solution {
public:
    
    vector<string> help(string s, unordered_set<string>& b){
        if(!s.size()){
            return {""};
        }
        vector<string> ans;
        for(auto cur:b){
            if(s.substr(0,cur.size())==cur){
                vector<string> small=help(s.substr(cur.size()),b);

                for(auto sen:small){

                    (sen.size())?ans.push_back(cur+" "+sen):ans.push_back(cur);
                }
            }
        }
        return ans;
    }
    
    vector<string> wordBreak(string s, vector<string>& b) {
        unordered_set<string> set(b.begin(), b.end());
        vector<string> ans= help(s,set);
        return ans;
    }
};