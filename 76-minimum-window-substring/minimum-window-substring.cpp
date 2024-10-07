class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(m>n) return "";
        vector<int> mpp(256, 0);
        for(int i=0; i<m; i++){
            mpp[t[i]]++;
        }

        int l=0;
        int r=0;
        int cnt = 0;
        int mini = 1e8;
        int minii = 0;
        while(r < n){
            if(mpp[s[r]] > 0){
                cnt++;
            }
            mpp[s[r]]--;

            while(cnt == m){
                // int size = r-l+1;
                if(r-l+1<mini){
                    mini = r-l+1;
                    minii = l;
                }
                mpp[s[l]]++;
                if(mpp[s[l]] > 0) cnt--;
                l++;
            }

            

            r++;
        }
        return mini == 1e8 ? "" : s.substr(minii, mini);
 
    }
};