class Solution {
public:
    int f(string word1, string word2, int i, int j, vector<vector<int>>& dp){

        if(j<0){
            return i+1;
        }
        if(i<0){
            return j+1;
        }

        if(dp[i][j]!=-1)return dp[i][j];
        if(word1[i]==word2[j]){
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

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        return f(word1, word2, n-1, m-1, dp);
    }
};