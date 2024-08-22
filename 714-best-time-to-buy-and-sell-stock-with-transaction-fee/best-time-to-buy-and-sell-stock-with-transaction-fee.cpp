class Solution {
public:
    int maxProfit(vector<int>& Arr, int fee) {
        int n = Arr.size();
        
        // vector<vector<int>> dp(n+1, vector<int>(2, 0));

        vector<int> prev(2, 0);
        vector<int> curr(2, 0);

        for(int ind = n-1; ind>=0; ind--){
            for(int buy = 1; buy>=0; buy--){
                if (buy == 0) { 
                    curr[buy] = max(0 + prev[0], -Arr[ind] + prev[1]);
                }

                if (buy == 1) { 
                    curr[buy] = max(0 + prev[1], Arr[ind] - fee + prev[0]);
                }
            }
            prev = curr;
        }

        return prev[0];
    }
};