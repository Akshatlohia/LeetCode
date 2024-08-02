class Solution {
public:
    int longestPalindromeSubseq(string s, int n) {
        string s2 = s;
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

    int minInsertions(string s) {
        int n = s.size();
        return (n-longestPalindromeSubseq(s, n));
    }
};