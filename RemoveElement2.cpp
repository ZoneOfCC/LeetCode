class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int rlocation = 0;
        for (int i = 0; i != nums.size(); ++i) {
            if (nums[i] != val) {
               nums[rlocation++] = nums[i];
            }
        }
        return rlocation;
    }
};