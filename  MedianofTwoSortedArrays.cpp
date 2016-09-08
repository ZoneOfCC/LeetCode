/*
* author: dongchagnzhang
* mail: dongchang.zhang@outlook.com
* time: 2016.09
*/
#include<iostream>
#include<vector>

using namespace std;
// code from here
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> tmp;
        int i, j;
        // nums1 is empty
        if (nums1.size() == 0) {
            tmp = nums2;
        }
        // nums2 is empty
        else if (nums2.size() == 0) {
            tmp = nums1;
        }
        // else
        else {
            for (i = 0, j = 0; i != nums1.size(); ++i) {
                if (i < nums1.size() && j < nums2.size() && nums1[i] < nums2[j]) {
                    tmp.push_back(nums1[i]);
                }
                else if (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]) {
                    
                    tmp.push_back(nums1[i]);
                    tmp.push_back(nums2[j++]);
                }
                else {
                    while (i < nums1.size() && j < nums2.size() && nums1[i] > nums2[j]) {
                        
                        tmp.push_back(nums2[j++]);
                    }
                    
                    tmp.push_back(nums1[i]);
                }
                
            }
            for (; j < nums2.size(); ++j) {
                    tmp.push_back(nums2[j]);

            }
        }
        double mid;
        int length = tmp.size();
        if (length % 2 == 1){
            mid = tmp[length / 2];
        }
        else {
            mid = (tmp[length / 2 - 1] + tmp[length /2]) / 2.0;
        }
        return mid;
    }
};
// end here


// for test
int main()
{
    vector<int> a = {1};
    vector<int> b = {2, 3};
    Solution s;
    cout << s.findMedianSortedArrays(a, b) << endl;  
    return 0;
}