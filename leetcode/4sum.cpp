#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution
{
  public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> result;
        vector<vector<vector<int>>> elements;
        for (int i = 0; i != nums.size(); ++i)
        {
            for (int j = i + 1; j != nums.size(); ++j)
            {
                vector<vector<int>> tmp;
                vector<int> tmp0, tmp1, tmp2;
                tmp0.push_back(nums[i] + nums[j]);
                tmp1.push_back(i);
                tmp1.push_back(j);
                tmp2.push_back(nums[i]);
                tmp2.push_back(nums[j]);
                tmp.push_back(tmp0);
                tmp.push_back(tmp1);
                tmp.push_back(tmp2);
                elements.push_back(tmp);
            }
        }
        sort(elements.begin(), elements.end(), 
        [](const vector<vector<int>> &v1, const vector<vector<int>> &v2) 
        { return v1[0][0] < v2[0][0]; });
        for (int l = 0; l < elements.size(); ++l)
        {
            for (int r = 1; r < elements.size(); ++r)
            {
                int sum = elements[l][0][0] + elements[r][0][0];

                if (sum == target)
                {
                    auto locs1 = elements[l][1];
                    auto locs2 = elements[r][1];
                    auto v1 = elements[l][2];
                    auto v2 = elements[r][2];
                    if (locs1[0] != locs2[0] && locs1[0] != locs2[1] &&
                        locs1[1] != locs2[0] && locs1[1] != locs2[1])
                    {
                        vector<int> element = v1;
                        element.push_back(v2[0]);
                        element.push_back(v2[1]);
                        sort(element.begin(), element.end());
                        if (result.end() == find(result.begin(), result.end(), element))
                            result.push_back(element);
                    }
                }
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};

int main()
{
    Solution s;

    vector<int> tmp = {1, 0, -1, 0, -2, 2};
    s.fourSum(tmp, 0);

