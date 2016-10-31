class Solution {
public:
    int strStr(string haystack, string needle) {
        int sh = haystack.size();
        int sn = needle.size();
        if (sh < sn) 
            return -1;
        for (int i = 0; i != sh - sn + 1; ++i) {
            int j = 0;
            for (; j < sn; ++j) {
                if (needle[j] != haystack[i + j]) {
                    break;
                }
            }
            if (j == sn) {
                return i;
            }
        }
        return -1;
    }
};