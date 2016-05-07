class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double res;
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<int> nums;
        int len = min(len1, len2);
        int len_t = len1+len2;
        int i=0, j=0;
        while (i<len1 && j<len2) {
            if(nums1[i]<=nums2[j]) {
                nums.push_back(nums1[i]);
                i += 1;
            }
            else {
                nums.push_back(nums2[j]);
                j += 1;
            }
        }
        if(i<len1) {
            while(i<len1) {
                nums.push_back(nums1[i]);
                i += 1;
            }
        }
        else if(j<len2) {
            while (j<len2) {
                nums.push_back(nums2[j]);
                j += 1;
            }
        }
        if (len_t%2)
            res = nums[len_t/2];
        else
            res = double((nums[len_t/2]+nums[len_t/2-1]))/2;
        return res;
    }
    
};