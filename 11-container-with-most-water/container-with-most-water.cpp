class Solution {
public:
    int maxArea(vector<int>& h) {
        int n = h.size();

        int l=0;
        int r=n-1;

        int res = 0;
        while(l<r){
            if(h[r]>h[l]){
                int area = (r-l)*h[l];
                res = max(res , area);
                l++;
            }
            else if(h[r]<h[l]){
                int area = (r-l)*h[r];
                res = max(res , area);
                r--;
            }
            else{
                int area = (r-l)*h[l];
                res = max(res , area);
                l++;
                r--;
            }
        }
        return res;
    }
};