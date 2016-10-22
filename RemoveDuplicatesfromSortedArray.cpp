class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        auto it = nums.begin();
        while (it != nums.end()) {
            if (s.find(*it) == s.end()) {
                s.insert(*it);
                ++it;
            }
            else {
                it = nums.erase(it);
            }
        }
        return s.size();
    }
};