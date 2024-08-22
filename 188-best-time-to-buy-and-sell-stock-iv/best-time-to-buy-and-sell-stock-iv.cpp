class Solution {
public:
    int maxProfit(int k, vector<int>& Arr) {
        int n = Arr.size();
        vector<vector<int>> dp(n+1, vector<int>(k*2+1, 0));

        for(int ind = n-1; ind>=0; ind--){
            for(int buy = k*2-1; buy>=0; buy--){
                int profit = 0;
                if (buy%2 == 0) { 
                    profit = max(0 + dp[ind + 1][buy], -Arr[ind] + dp[ind + 1][buy+1]);
                }

                if (buy%2 == 1) { 
                    profit = max(0 + dp[ind + 1][buy], Arr[ind] + dp[ind + 1][buy+1]);
                }
                dp[ind][buy] = profit;
            }
        }

        int ans = dp[0][0];
        return ans;
    }
};