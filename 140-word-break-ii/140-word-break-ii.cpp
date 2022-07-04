class Solution {
public:
    
    vector<string> help(string s, unordered_set<string>& b, map<string,vector<string>> &mp){
        if(!s.size()){
            return {""};
        }
        if(mp.find(s)!=mp.end()){
            return mp[s];
        }
        vector<string> ans;
        for(auto cur:b){
            if(s.substr(0,cur.size())==cur){
                    vector<string> small=help(s.substr(cur.size()),b,mp);

                    for(auto sen:small){

                        (sen.size())?ans.push_back(cur+" "+sen):ans.push_back(cur);
                    }
            }
        }
        mp[s]=ans;
        return ans;
    }
    
    vector<string> wordBreak(string s, vector<string>& b) {
        unordered_set<string> set(b.begin(), b.end());
        map<string,vector<string>> mp;
        vector<string> ans= help(s,set,mp);
        return ans;
    }
};