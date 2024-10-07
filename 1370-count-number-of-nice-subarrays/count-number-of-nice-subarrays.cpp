class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
    int left = 0, right = 0, oddCount = 0, count = 0, prefix = 0;

    while (right < nums.size()) {
        // Expand the window by moving the `right` pointer
        if (nums[right] % 2 == 1) {
            oddCount++;
            prefix = 0;  // Reset prefix count as we found a new odd number
        }

        // When we have exactly `k` odd numbers in the window
        while (oddCount == k) {
            if (nums[left] % 2 == 1) {
                oddCount--;
            }
            prefix++;
            left++;
        }

        // Add the number of valid subarrays ending at `right`
        count += prefix;
        right++;
    }

    return count;

    }


};