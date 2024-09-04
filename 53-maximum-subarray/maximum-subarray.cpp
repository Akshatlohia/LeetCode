class Solution {
public:
    // int f(int ind, int flag, vector<int>& nums, vector<vector<int>>& dp){
    //     if(ind == 0){
    //         if(flag == 0){
    //             return -1e8;
    //         }
    //         return 0;
    //     }


    //     if(dp[ind][flag] != -1) return dp[ind][flag];

    //     if(flag == 0){
    //         int pick = nums[ind-1] + f(ind-1, flag+1, nums, dp);

    //         int notPick = f(ind-1, flag, nums, dp);

    //         return dp[ind][flag] = max(pick, notPick);
    //     }

    //     if(flag == 1){
    //         int pick = nums[ind-1] + f(ind-1, flag, nums, dp);

    //         return dp[ind][flag] = max(pick, 0);
    //     }

    //     return 0;
    // }


    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>> dp(n+1, vector<int>(2, 0));

        vector<int> prev(2,0);
        vector<int> curr(2,0);

        prev[0] = -1e8;

        for(int ind=1;ind<=n;ind++){
            for(int flag=0;flag<2;flag++){
                if(flag == 0){
                    int pick = nums[ind-1] + prev[flag+1];

                    int notPick = prev[flag];

                    curr[flag] = max(pick, notPick);
                }

                if(flag == 1){
                    int pick = nums[ind-1] + prev[flag];

                    curr[flag] = max(pick, 0);
                }
            }
            prev = curr;
        }



        return prev[0];
    }
};