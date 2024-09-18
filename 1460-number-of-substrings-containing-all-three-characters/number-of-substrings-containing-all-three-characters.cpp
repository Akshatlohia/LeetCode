class Solution {
public:
    int numberOfSubstrings(string s) {
        int count =0;
        int n = s.size();
        int arr[3] = {-1, -1, -1};
        for(int i = 0; i<n; i++){
            arr[s[i]-'a'] = i;
            count += (1 + min(arr[0], min(arr[1], arr[2])));
        }
        return count;
    }
};