class Solution {
public:
    int f(int ind, int amt,  vector<int>& coins, vector<vector<int>>& dp){
        if(ind == 0){
            if(amt%coins[ind]==0) return 1;
            else return 0;
        }
        if(dp[ind][amt]!=-1)return dp[ind][amt];
        int notTake = f(ind-1, amt, coins, dp);
        int take = 0;
        if(amt>=coins[ind]){
            take = f(ind, amt-coins[ind], coins, dp);
        }

        return dp[ind][amt] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount+1, 0));

        

        for(int i = 0 ; i<=amount; i++){
            if(i%coins[0]==0) dp[0][i] = 1;
        }

        for(int ind=1; ind<n; ind++){
            for(int amt = 0; amt<=amount; amt++){
                int notTake = dp[ind-1][amt];
                int take = 0;
                if(amt>=coins[ind]){
                    take = dp[ind][amt-coins[ind]];
                }

                dp[ind][amt] = take + notTake;
            }
        }

        return dp[n-1][amount];
    }
};