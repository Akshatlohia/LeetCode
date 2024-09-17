class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        queue < int > q;

        int left = 0, right = 0;
        int n = nums.size();
        int len = 0;
        while (right < n) {
            if(nums[right]==0){
                if(k==0){
                    left = right+1;
                }
                else if(q.size()>=k){
                    left = q.front()+1;
                    q.pop();
                    q.push(right);
                }
                else{
                    q.push(right);
                }
            }
            len = max(len, right - left + 1);
            right++;
        }
        return len;
    }
};