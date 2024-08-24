class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> mat(26, vector<int>(26, 1e9));

        // for(int k=0; k<26; k++){
        //     mat[k][k] = 0;
        // }

        for(int i=0; i<original.size(); i++){
            mat[original[i] - 'a'][changed[i] - 'a'] = min(cost[i], mat[original[i] - 'a'][changed[i] - 'a']);
        }

        for(int k=0; k<26; k++){
            for(int i=0; i<26; i++){
                for(int j=0; j<26; j++){
                    mat[i][j] = min(mat[i][j], mat[i][k]+mat[k][j]);
                }
            }
        }

        long long ans = 0;
        for(int i=0; i<source.size(); i++){
            if(source[i] != target[i]){
                if(mat[source[i] - 'a'][target[i] - 'a'] == 1e9){
                    return -1;
                }
                ans += mat[source[i] - 'a'][target[i] - 'a'];
            }
        }
        return ans;
    }
};