class Solution {
public:
    // Assign the size as per maximum value for different params
    int dp[100][100][21];
    // Maximum cost possible plus 1
    const int MAX_COST = 1000001;
    
    int solve(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target, int i,
                    int count, int prev) {
        if (i == m) {
            // If all houses are traversed, check if the neighbor count is as expected or not
            return count == target ? 0 : MAX_COST;
        }
        
        if (count > target) {
            // If the neighborhoods are more than the threshold, we can't have target neighborhoods
            return MAX_COST;
        }
        
        // We have already calculated the answer so no need to go into recursion
        if (dp[i][count][prev] != -1) {
            return dp[i][count][prev];
        }
        
        int ans = MAX_COST;
        // If the house is already painted, update the values accordingly
        if (houses[i]) {
            int newcount = (houses[i]==prev)?count:count+1;
            ans = min(ans, solve(houses, cost, m, n, target, i+1, newcount, houses[i]));
        } else {
            
            // If the house is not painted, try every possible color and store the minimum cost
            for (int c = 1; c <= n; c++) {
                int newcount = (c==prev)?count:count+1;
                ans = min(ans, cost[i][c-1]
                    + solve(houses, cost, m, n, target, i+1, newcount, c));
            }
        }
        
        // Return the minimum cost and also storing it for future reference (memoization)
        return dp[i][count][prev] = ans;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        // Marking all values to -1 to denote that we don't have the answer ready for these params yet
        memset(dp, -1, sizeof(dp));
        int ans = solve(houses, cost, m, n, target, 0, 0, 0);
        
        // Return -1 if the answer is MAX_COST as it implies no answer possible
        return ans == MAX_COST ? -1 : ans;
    }
};