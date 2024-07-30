class Solution {
public:
    // int f(string s1, string s2, int ind1, int ind2, vector<vector<int>> &dp){
    //     if(ind1 == 0 || ind2 == 0){
    //         return 0;
    //     }
    //     if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
    //     if(s1[ind1-1] == s2[ind2-1]){
    //         return dp[ind1][ind2] = 1+f(s1, s2, ind1-1, ind2-1, dp);
    //     }
    //     else{
    //         return dp[ind1][ind2] = max(f(s1, s2, ind1-1, ind2, dp),f(s1, s2, ind1, ind2-1, dp));
    //     }
    // }
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        int n = s.size();
        reverse(s2.begin(), s2.end());

        // vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        vector<int>curr(n+1, 0);
        vector<int>prev(n+1, 0);

        for(int ind1 = 1; ind1<=n; ind1++){
            for(int ind2 = 1; ind2<=n; ind2++){
                if(s[ind1-1] == s2[ind2-1]){
                    curr[ind2] = 1+prev[ind2-1];
                }
                else{
                    curr[ind2] = max(prev[ind2],curr[ind2-1]);
                }
            }
            prev = curr; 
        }

        return prev[n];
    }
};