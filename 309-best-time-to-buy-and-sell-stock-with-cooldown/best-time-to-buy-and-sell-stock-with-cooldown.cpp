class Solution {
public:
    int maxProfit(vector<int>& Arr) {
        int n = Arr.size();
        
        vector<vector<int>> dp(n+2, vector<int>(n+1, 0));

        for(int ind = n-1; ind>=0; ind--){
            for(int buy = n-1; buy>=0; buy--){
                int profit = 0;
                if (buy%2 == 0) { 
                    profit = max(0 + dp[ind + 1][buy], -Arr[ind] + dp[ind + 1][buy+1]);
                }

                if (buy%2 == 1) { 
                    profit = max(0 + dp[ind + 1][buy], Arr[ind] + dp[ind + 2][buy+1]);
                }
                dp[ind][buy] = profit;
            }
        }

        int ans = dp[0][0];
        return ans;
    }
};