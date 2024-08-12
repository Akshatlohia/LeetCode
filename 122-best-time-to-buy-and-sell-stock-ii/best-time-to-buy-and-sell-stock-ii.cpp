class Solution {
public:
    int getAns(vector<int>& Arr, int ind, int buy, int n, vector<vector<int>> &dp) {
        if (ind == n) {
            return 0;
        }
        if (dp[ind][buy] != -1) {
            return dp[ind][buy];
        }

        int profit = 0;

        if (buy == 0) { 
            profit = max(0 + getAns(Arr, ind + 1, 0, n, dp), -Arr[ind] + getAns(Arr, ind + 1, 1, n, dp));
        }

        if (buy == 1) { 
            profit = max(0 + getAns(Arr, ind + 1, 1, n, dp), Arr[ind] + getAns(Arr, ind + 1, 0, n, dp));
        }

        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int>& Arr) {
        int n = Arr.size();
        
        // vector<vector<int>> dp(n+1, vector<int>(2, 0));

        vector<int> prev(2, 0);
        vector<int> curr(2, 0);

        for(int ind = n-1; ind>=0; ind--){
            for(int buy = 1; buy>=0; buy--){
                int profit = 0;
                if (buy == 0) { 
                    profit = max(0 + prev[0], -Arr[ind] + prev[1]);
                }

                if (buy == 1) { 
                    profit = max(0 + prev[1], Arr[ind] + prev[0]);
                }
                curr[buy] = profit;
            }
            prev = curr;
        }

        return prev[0];
    }
};