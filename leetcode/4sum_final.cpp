class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int length = nums.size();
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        set<vector<int>> pool;
        for (int i = 0; i < length; ++i) {
            for (int j = i + 1; j < length; ++j) {
                int l = j + 1;
                int r = length - 1;
                while (l < r) {
                    
                    int sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum > target) {
                        --r;
                    } else if (sum < target) {
                        ++l;
                    }
                    else {
                        vector<int> tmp;
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[j]);
                        tmp.push_back(nums[l]);
                        tmp.push_back(nums[r]);
                        pool.insert(tmp);
                        l++;
                        r--;
                    }
                }
            }
        }
        for (auto p : pool) result.push_back(p);
        return result;
        
    }
};