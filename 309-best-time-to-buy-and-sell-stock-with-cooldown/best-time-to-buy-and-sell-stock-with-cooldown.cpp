class Solution {
public:
    int maxProfit(vector<int>& Arr) {
        int n = Arr.size();
        
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        for(int ind = n-1; ind>=0; ind--){
                    dp[ind][0] = max(0 + dp[ind + 1][0], -Arr[ind] + dp[ind + 1][1]);

                    if(ind == n-1){
                        dp[ind][1] = max(0 + dp[ind + 1][1], Arr[ind] + dp[ind + 1][0]);
                    }
                    else
                        dp[ind][1] = max(0 + dp[ind + 1][1], Arr[ind] + dp[ind + 2][0]);
        }

        int ans = dp[0][0];
        return ans;
    }
};