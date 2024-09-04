class Solution {
public:
    int f(int ind, int flag, vector<int>& nums, vector<vector<int>>& dp){
        // if(flag == 2){
        //     return 0;
        // }

        if(ind<0){
            if(flag == 0){
                return -1e8;
            }
            return 0;
        }


        if(dp[ind][flag] != -1) return dp[ind][flag];

        if(flag == 0){
            int pick = nums[ind] + f(ind-1, flag+1, nums, dp);

            int notPick = f(ind-1, flag, nums, dp);

            return dp[ind][flag] = max(pick, notPick);
        }

        if(flag == 1){
            int pick = nums[ind] + f(ind-1, flag, nums, dp);

            int notPick = f(ind-1, flag+1, nums, dp);

            return dp[ind][flag] = max(pick, notPick);
        }

        return 0;
    }


    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));

        return f(n-1, 0, nums, dp);
    }
};