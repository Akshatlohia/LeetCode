class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int zeroCount = 0;
        int maxLen = 0;
        
        while (right < nums.size()) {
            // If the current element is 0, increment the zero count
            if (nums[right] == 0) {
                zeroCount++;
            }
            
            // If the number of zeros exceeds k, shrink the window from the left
            while (zeroCount > k) {
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++; // Move the left pointer to shrink the window
            }
            
            // Update the maximum window length
            maxLen = max(maxLen, right - left + 1);
            
            // Expand the window by moving the right pointer
            right++;
        }
        
        return maxLen;
    }
};
