class Solution {
public:
    int getAns(vector<int>& Arr, int ind, int buy, int n, vector<vector<int>> &dp) {
        if (ind == n) {
            return 0;
        }
        if (buy >= 4){
            return 0;
        }
        
        if (dp[ind][buy] != -1) {
            return dp[ind][buy];
        }

        int profit = 0;

        if (buy%2 == 0) { 
            profit = max(0 + getAns(Arr, ind + 1, buy, n, dp), -Arr[ind] + getAns(Arr, ind + 1, buy+1, n, dp));
        }

        if (buy%2 == 1) { 
            profit = max(0 + getAns(Arr, ind + 1, buy, n, dp), Arr[ind] + getAns(Arr, ind + 1, buy+1, n, dp));
        }

        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int>& Arr) {
        int n = Arr.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));

        if (n == 0) {
            return 0;
        }

        int ans = getAns(Arr, 0, 0, n, dp);
        return ans;
    }
};