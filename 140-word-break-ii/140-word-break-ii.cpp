class Solution {
public:
    
    vector<string> help(string s, vector<string> b){
        if(!s.size()){
            return {""};
        }
        vector<string> ans;
        set<string> chk;    //check if cur has already occurred
        for(auto cur:b){
            if(chk.find(cur)!=chk.end()) continue;
            chk.insert(cur);
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
        vector<string> ans= help(s,b);
        sort(ans.begin(),ans.end());
        return ans;
    }
};