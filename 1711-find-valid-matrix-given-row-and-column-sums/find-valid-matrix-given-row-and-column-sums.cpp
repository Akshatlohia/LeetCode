class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size();
        int m = colSum.size();

        vector<vector<int>> ans(n, vector<int>(m, 0));
        // for(int i = 0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         if(rowSum[i]!=0 && colSum[j]!=0){
        //             int val = min(rowSum[i], colSum[j]);
        //             ans[i][j]=val;
        //             rowSum[i] -= val;
        //             colSum[j] -= val;
        //         }
        //     }
        // 
        // }

        int i = 0, j = 0;
        while(i<n && j<m){
            int val = min(rowSum[i], colSum[j]);
            ans[i][j]=val;
            rowSum[i] -= val;
            colSum[j] -= val;

            if(rowSum[i]==0)i++;
            if(colSum[j]==0)j++;
        }

        return ans;
    }
};