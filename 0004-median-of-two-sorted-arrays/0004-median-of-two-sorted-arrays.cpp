class Solution {
public:
    static int compF(const void *a, const void *b){
        return(*(int*)a - *(int*)b);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        int len = nums1.size();
        qsort(nums1.data(), nums1.size(), sizeof(int), compF);

        if(len % 2){
            return nums1[len/2];
        }
        else{
            return (nums1[len/2] + nums1[len/2 - 1])/2.0;
        }
    }
};