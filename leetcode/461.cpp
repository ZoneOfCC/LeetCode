/* author: dongchangzhang */
/* time: 2017年06月16日 星期五 10时43分41秒 */
class Solution {
public:
    int hammingDistance(int x, int y)
    {
        int r = x ^ y, sum = 0;
        for (int i = 0; i < 32; ++i) {
            sum += r & 1;
            r >>= 1;
        }
        return sum;
    }
};
