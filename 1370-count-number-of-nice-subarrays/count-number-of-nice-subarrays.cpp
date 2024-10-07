class Solution {
public:
    int f(vector<int>& nums, int k){
        if(k<0)return 0;
        int l=0;
        int r=0;
        int cnt=0;
        int oddCount=0;

        while(r<nums.size()){
            if(nums[r] % 2 == 1){
                oddCount++;
            }
            while(oddCount > k){
                if(nums[l] % 2 == 1){
                    oddCount--;
                }
                l++;
            }
            cnt+=r-l+1;
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return f(nums, k) - f(nums, k-1);
    }


};