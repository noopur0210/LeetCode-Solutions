class Solution {
public:
    
    static bool cmp (vector<int> a, vector<int> b){
        return a[1]>b[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        
        int res=0, remSize=truckSize ;
        
        for(int i=0; i<boxTypes.size(); i++){
            
            if(remSize==0)  break;
            
            if(boxTypes[i][0]<=remSize){
                res+=(boxTypes[i][0]*boxTypes[i][1]);
                remSize -= boxTypes[i][0];
            }
            else{
                res+=(remSize*boxTypes[i][1]);
                remSize=0;
            }
            
        }
        
        return res;
    }
};