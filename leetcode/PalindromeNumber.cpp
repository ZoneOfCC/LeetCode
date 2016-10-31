#include <iostream>
#include <vector>

using namespace std;

// code from here
class Solution
{
  public:
    bool isPalindrome(int x) // 注意负数不是回文数字
    {
        vector<int> pos;
        if (x < 0) return false;
        int tmp = x;
        for (; tmp != 0;)
        {
            pos.push_back(tmp % 10);
            tmp /= 10;
        }
        int begin = 0;
        int end = pos.size() - 1;
        while (begin <= end) {
            if (pos[begin++] != pos[end--]) {
                return false;
            }
        }
        return true;
    }
};
// code end here
int main()
{
    Solution s;
    cout << s.isPalindrome(-2147447412) << endl;
    return 0;
}