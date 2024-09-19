class Solution {
public:
    int characterReplacement(string s, int k) {
        int arr[26] = {0};
        int l=0;
        int r=0;
        int len = 0;
        int maxf = 0;
        while(r < s.size()){
            arr[s[r]-'A']++;
            maxf = max(maxf, arr[s[r]-'A']);
            if((r-l+1) - maxf <= k){
                len = max(len, r-l+1);
            }
            else{
                arr[s[l]-'A']--;
                l++;
            }
            r++;
        }
        return len;
    }
};