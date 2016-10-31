#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i != nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            if (i + 2 >= nums.size()) break;
            if ((nums[i] + nums[nums.size() - 1] + nums[nums.size() - 2] < 0))
                continue;
            if (nums[i] + nums[i + 1] + nums[i + 2] > 0)
                break;
            int bcursor = i + 1;
            int ecursor = nums.size() - 1;
            while (bcursor < ecursor) {
                
                int sum = nums[i] + nums[bcursor] + nums[ecursor];
                if (sum > 0) --ecursor;
                else if (sum < 0) ++bcursor;
                else {
                    if (bcursor > i && ecursor < nums.size() - 1 
                        && nums[bcursor] == nums[bcursor - 1] 
                        && nums[ecursor] == nums[ecursor + 1]) {
                    ++bcursor;
                    --ecursor;
                    continue;
                }
                    vector<int> tmp = {nums[i], nums[bcursor], nums[ecursor]};
                    result.push_back(tmp);
                    --ecursor;
                    ++bcursor;
                }

            }
        }
        return result;
    }
};
int main() {
    Solution s;
    vector<int> t = {-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};
    for (auto &v : s.threeSum(t)){
        for (auto i : v) 
            cout << i << " ";
            cout << endl;}
}