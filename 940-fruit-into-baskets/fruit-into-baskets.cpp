class Solution {
public:
    int totalFruit(vector<int>& n) {
        int l=0;
        int r=0;
        int len=0;
        unordered_map<int, int> mpp;

        while(r<n.size()){
            mpp[n[r]]++;
            if(mpp.size()>2){
                mpp[n[l]]--;
                if(mpp[n[l]] == 0){
                    mpp.erase(n[l]);
                }
                l++;
            }
            if(mpp.size()<=2){
                len = max(len, r-l+1);
            }
            r++;
        }
        return len;
    }
};