class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, int vis[], int n){
        vis[node] = 1;
        for(int i=0;i<n;i++){
            if(adj[node][i] == 1 && vis[i] != 1){
                dfs(i, adj, vis, n);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int vis[n];
        for (int i = 0; i < n; ++i) {
            vis[i] = 0;
        }
        int ans = 0;
        for(int i =0; i<n; i++){
            if(vis[i] == 0){
                ans++;
                dfs(i, isConnected, vis, n);
            }
        }
        return ans;
    }
};