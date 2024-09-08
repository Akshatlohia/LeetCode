class Solution {
public:
    int maxArea(vector<int>& h) {
        int n = h.size();

        int l=0;
        int r=n-1;

        int res = 0;
        while(l<r){
            int area = (r-l)*min(h[l], h[r]);
            res = max(res , area);

            if(h[r]>h[l]){
                l++;
            }
            else if(h[r]<h[l]){
                r--;
            }
            else{
                l++;
                r--;
            }
        }
        return res;
    }
};