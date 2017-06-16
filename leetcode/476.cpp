class Solution {
public:
    int findComplement(int num) {
        int flag = 1, tmp = num;
        for (int i = 1; i < 32 && flag <= num; ++i) {
                tmp ^= flag;
                flag *= 2;
        }
        return tmp;
    }
};