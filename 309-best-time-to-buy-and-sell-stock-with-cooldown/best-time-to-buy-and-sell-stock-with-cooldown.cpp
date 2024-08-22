class Solution {
public:
    int maxProfit(vector<int>& Arr) {
        int n = Arr.size();
        
        vector<vector<int>> dp(n+2, vector<int>(2, 0));

        for(int ind = n-1; ind>=0; ind--){
            for(int buy = 1; buy>=0; buy--){
                int profit = 0;
                if (buy == 0) { 
                    profit = max(0 + dp[ind + 1][0], -Arr[ind] + dp[ind + 1][1]);
                }

                if (buy == 1) { 
                    profit = max(0 + dp[ind + 1][1], Arr[ind] + dp[ind + 2][0]);
                }
                dp[ind][buy] = profit;
            }
        }

        int ans = dp[0][0];
        return ans;
    }
};