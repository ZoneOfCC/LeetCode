class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        auto it_last = nums.begin();
        for (auto it = nums.begin() + 1; it != nums.end();) {
           if (*it == *(it - 1)) {
                while (it != nums.end() && *it == *(it - 1)) {
                    ++it;
                }
            }
            if (it == nums.end()) break;
            ++it_last;
            *it_last = *it;
            ++it;
        }
        return (it_last - nums.begin() + 1);
    }
};