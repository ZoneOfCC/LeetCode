/*
* author: dongchagnzhang
* mail: dongchang.zhang@outlook.com
* time: 2016.09
*/
// for test
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


// the code for leetcode from here

class Solution {
public:
    /*
    * 传入vector和target
    * 调用getNum()得到两个目标数据
    * 遍历nums得到两个数据的索引并且返回
    */
    vector<int> twoSum(vector<int>& nums, int target) {
        // 找到第一个数据？
        bool find_0 = false;
        // 找到第二个数据？  
        bool find_1 = false;
        // nums的copy， 会被排序
        vector<int> tmp = nums;
        // 得到两个目标数据的vector
        vector<int> rtmp = getNum(tmp, target);
        // 需要返回的数据
        vector<int> result;
        for (int i = 0; i != nums.size(); ++i) {
            if (!find_0 && nums[i] == rtmp[0]) {
                find_0 = true;
                result.push_back(i);
            }
            else if (!find_1 && nums[i] == rtmp[1]) {
                find_1 = true;
                result.push_back(i);
            }
            if (find_0 && find_1)
                break;
        }
        return result;
    }
    /*
    * 传入vector和target，对vector进行排序
    * 从vector结束位置向前遍历，对每一个数和从开始位置到当前位置进行加和
    * 找到和为target的两个数值 返回
    */
    vector<int> getNum(vector<int>& nums, int target) {
        // 返回的数据 ： 两个目标数据
        std::vector<int> result;
        sort(nums.begin(), nums.end());
        for (int i = nums.size() - 1; i != -1; --i) {
            for (int j = 0; j != i; ++j) {
                if (nums[i] + nums[j] > target) 
                    break;
                else if (nums[i] + nums[j] == target) {
                    result.push_back(nums[j]);
                    result.push_back(nums[i]);
                    return result;
                }
            }
        }
        return result;
    }
    
};

// end here


//for test
int main()
{
    vector<int> v = {0,4,3,0};
    Solution s;
    for (auto n :s.twoSum(v, 0)) std::cout << n << std::endl;
}