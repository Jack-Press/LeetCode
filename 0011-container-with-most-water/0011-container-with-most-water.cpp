class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxA = 0;
        int l = 0;
        int r = height.size() - 1;
        while(l < r){
            if(height[l] < height[r]){
                maxA = max(height[l] * (r - l), maxA);
                l++;
            }
            else{
                maxA = max(height[r] * (r - l), maxA);
                r--;
            }
        }
        return maxA;
    }
};