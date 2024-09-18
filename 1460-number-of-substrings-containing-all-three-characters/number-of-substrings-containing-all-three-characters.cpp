class Solution {
public:
    int numberOfSubstrings(string n) {
        int count =0;
        int s = n.size();
        int l=0;
        int r=0;
        unordered_map<int, int> mpp;

        while(r<s){
            mpp[n[r]]++;
            while(mpp.size() == 3){
                count += s-r;
                mpp[n[l]]--;
                if(mpp[n[l]] == 0){
                    mpp.erase(n[l]);
                }
                l++;
            }
            r++;
        }
        return count;
    }
};