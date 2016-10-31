#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[nums.size() / 2] + nums[nums.size() -1];
        int sub = abs(closest - target);
        for (int i = 0; i != nums.size(); ++i) {
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r) {
                int closest_tmp = nums[i] + nums[l] + nums[r];
                int sub_tmp = abs(closest_tmp - target);
                if (closest_tmp > target) {
                    if (sub > sub_tmp) {
                        closest = closest_tmp;
                        sub = sub_tmp;
                    }
                    --r;
                }
                else if (closest_tmp < target) {
                    if (sub > sub_tmp) {
                        closest = closest_tmp;
                        sub = sub_tmp;
                    }
                    ++l;
                }
                else {
                    return target;
                }
                
            }
        }
        return closest;
    }
};
int main() {
    Solution s;
    vector<int> v = {1,1,-1};
    cout <<s.threeSumClosest(v, 2) << endl;
    return 0;
}