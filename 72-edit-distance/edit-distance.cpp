class Solution {
public:
    int f(string word1, string word2, int i, int j, vector<vector<int>>& dp){

        if(j==0){
            return i;
        }
        if(i==0){
            return j;
        }

        if(dp[i][j]!=-1)return dp[i][j];
        if(word1[i-1]==word2[j-1]){
            return dp[i][j] = f(word1, word2, i-1, j-1, dp);
        }
        else{
            int insert = 1 + f(word1, word2, i, j-1, dp);

            int del = 1 + f(word1, word2, i-1, j, dp);

            int replace = 1 + f(word1, word2, i-1, j-1, dp);

            return dp[i][j] = min(insert, min(del, replace));
        }

    }


    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i=1; i<=n; i++){
            dp[i][0] = i; 
        }

        for(int j=1; j<=m; j++){
            dp[0][j] = j; 
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    int insert = 1 + dp[i][j-1];

                    int del = 1 + dp[i-1][j];

                    int replace = 1 + dp[i-1][j-1];

                    dp[i][j] = min(insert, min(del, replace));
                }
            }
        }
        return dp[n][m];
    }
};