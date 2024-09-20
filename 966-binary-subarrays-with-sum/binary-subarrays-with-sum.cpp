class Solution {
public:
    int f(vector<int>& arr, int k){
        if(k<0)return 0;
        int l=0;
        int r=0;
        int cnt=0;
        int sum=0;
        while(r < arr.size()){
            sum += arr[r];
            while(sum>k){
                sum-=arr[l];
                l++;
            }
            cnt += r-l+1;
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& arr, int k) {        
        return f(arr, k) - f(arr, k-1); 
    }
};