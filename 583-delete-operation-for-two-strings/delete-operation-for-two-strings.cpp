class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<int> prev(m + 1, 0), cur(m + 1, 0);


        for (int ind1 = 1; ind1 <= n; ind1++) {
            for (int ind2 = 1; ind2 <= m; ind2++) {
                if (s1[ind1 - 1] == s2[ind2 - 1])
                    cur[ind2] = 1 + prev[ind2 - 1];
                else
                    cur[ind2] = max(prev[ind2], cur[ind2 - 1]);
            }
            prev = cur;
        }

        return prev[m];
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        return (n+m-2*longestCommonSubsequence(word1, word2));
    }
};