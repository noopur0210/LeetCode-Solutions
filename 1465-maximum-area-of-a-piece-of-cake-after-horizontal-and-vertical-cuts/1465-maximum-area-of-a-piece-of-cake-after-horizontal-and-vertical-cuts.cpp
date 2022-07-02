class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        long long int maxVerticalDist = max(verticalCuts[0], w-verticalCuts.back());
        long long int maxHorizontalDist = max(horizontalCuts[0], h-horizontalCuts.back());
        
        
        for(int i=1; i<horizontalCuts.size(); i++)
            maxHorizontalDist = max(maxHorizontalDist, (long long int)(horizontalCuts[i]-horizontalCuts[i-1]));
        
        
        for(int j=1; j<verticalCuts.size(); j++)
            maxVerticalDist = max(maxVerticalDist, (long long int)(verticalCuts[j]-verticalCuts[j-1]));
        
        
        
        long long int eps = 1e9+7;
        
        return maxHorizontalDist*maxVerticalDist%eps;
    }
};