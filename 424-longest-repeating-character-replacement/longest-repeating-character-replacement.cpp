class Solution {
public:
int findMax(int arr[], int size) {
    int maxElement = arr[0]; // Initialize with the first element

    for (int i = 1; i < size; i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i]; // Update maxElement if a larger value is found
        }
    }

    return maxElement;
}
    int characterReplacement(string s, int k) {
        int arr[26] = {0};
        int l=0;
        int r=0;
        int len = 0;
        while(r < s.size()){
            arr[s[r]-'A']++;
            if((r-l+1) - findMax(arr, 26) <= k){
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