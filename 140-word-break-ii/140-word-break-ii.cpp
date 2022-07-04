class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        
        for(string w: wordDict){
            if(s.substr(0,w.length()) == w){
                if(w.length()==s.length())
                    res.push_back(w);
                else{
                    vector<string> temp = wordBreak(s.substr(w.length()), wordDict);
                    for(string t: temp)
                        res.push_back(w + " " + t);
                }
            }               
        }
        
        return res;
    }
};