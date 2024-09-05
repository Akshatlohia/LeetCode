class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> pre(n);
        pre[0] = 1;

        for(int i=1; i<n;i++){
            pre[i] = pre[i-1]*nums[i-1];
        }

        int s = nums[n-1];
        nums[n-1] = 1;
        for(int i = n-2; i>=0; i--){
            int num = nums[i+1]*s;
            s=nums[i];
            nums[i]=num;
        }

        for(int i=0; i<n; i++){
            nums[i] = nums[i]*pre[i];
        }


        return nums;
    }
};