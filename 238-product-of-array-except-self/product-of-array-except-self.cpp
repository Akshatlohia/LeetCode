class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> pre(n);
        pre[0] = 1;

        for(int i=1; i<n;i++){
            pre[i] = pre[i-1]*nums[i-1];
        }

        int s = 1;
        for(int i = n-1; i>=0; i--){
            pre[i] = pre[i]*s;
            s=s*nums[i];
        }


        return pre;
    }
};