class Solution {
public:
    
    void solve(int col, int n, vector<string>& ds, vector<vector<string>>& ans, vector<int>& leftrow, vector<int>& upperDiagonal, vector<int>& lowerDiagonal){
        
        if(col==n){
            ans.push_back(ds);
            return;
        }
        
        for(int row=0; row<n; row++){
            if(leftrow[row]==0 && upperDiagonal[row+col]==0 && lowerDiagonal[n-1+row-col]==0){
                leftrow[row] = 1;
                upperDiagonal[row+col] = 1;
                lowerDiagonal[n-1+row-col] = 1;
                
                ds[row][col] = 'Q';
                
                solve(col+1,n,ds,ans,leftrow,upperDiagonal,lowerDiagonal);
                
                leftrow[row] = 0;
                upperDiagonal[row+col] = 0;
                lowerDiagonal[n-1+row-col] = 0;
                
                ds[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> ds(n);
        string s(n, '.');
        
        for(int i=0; i<n; i++)
            ds[i] = s;
        
        vector<int> leftrow(n,0), upperDiagonal(2*n-1,0), lowerDiagonal(2*n-1,0);
        solve(0,n,ds,ans,leftrow,upperDiagonal,lowerDiagonal);
        return ans;
    }
};