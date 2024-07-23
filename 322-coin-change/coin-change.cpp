class Solution {
public:
    int f(int ind, int amt, vector<int>& coins, vector<vector<int>> &dp){
        if(ind == 0){
            if(amt % coins[0]==0) return amt/coins[0];
            else return 1e9;
        }
        if(dp[ind][amt] != -1)return dp[ind][amt];
        int notTake = 0 + f(ind-1, amt, coins, dp);
        int take = INT_MAX;
        if(coins[ind] <= amt){
            take = 1 + f(ind, amt-coins[ind], coins, dp);
        }

        return dp[ind][amt] = min(notTake , take);

    }
    int coinChange(vector<int>& coins, int amt) {
        int n = coins.size();

        vector<int> prev(amt+1, 0), curr(amt+1, 0);
        // vector<vector<int>> dp(n, vector<int>(amt+1 , -1));

        for(int i=0; i<=amt; i++){
            if(i % coins[0] == 0) prev[i] = i/coins[0];
            else prev[i] = 1e9;
        }

        for(int i=1; i<n; i++){
            for(int j=0; j<= amt; j++){
                int notTake = 0 + prev[j];
                int take = INT_MAX;
                if(coins[i] <= j){
                    take = 1 + curr[j-coins[i]];
                }

                curr[j] = min(notTake , take);
            }
            prev = curr;
        }

        int ans = prev[amt];

        if(ans >= 1e9) return -1;
        else return ans;
    }
};