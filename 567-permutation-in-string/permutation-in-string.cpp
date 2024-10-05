class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if(m<n) return false;
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        for(int i=0; i<n; i++){
            freq1[s1[i] - 'a']++;
        }
        for(int i=0; i<n; i++){
            freq2[s2[i] - 'a']++;
        }
        if(freq1 == freq2) return true;
        int i=1;
        int j=n;
        while(j< m){
            freq2[s2[i-1] - 'a']--;
            freq2[s2[j] - 'a']++;
            if(freq1 == freq2) return true;
            i++;
            j++;
        }
        return false;
    }
};