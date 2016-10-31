/*
* author: dongchagnzhang
* mail: dongchang.zhang@outlook.com
* time: 2016.09.08
*/
#include<iostream>
#include<vector>
using namespace std;
// code from here
class Solution {
public:
    int reverse(int x) { // 注意int类型32位的范围，超出范围返回0
        vector<int> pos; //用于存储数字的每一位，从个位开始
        int tmp = x > 0 ? x : -x;
        for (; tmp != 0;) {
            pos.push_back(tmp % 10); // 通过取余数得到最低位
            tmp /= 10; // 除以10后原来的十位变为个位
        }
        long long sum = 0; // 将要返回的
        for (auto c : pos) {
            sum = sum * 10 + c; //将各个数字组成数字
        }
        sum = (x > 0) ? sum : -sum; // 正负号
        if (sum > 2147483647 || sum < -2147483648) // 溢出判断
            sum = 0;
        return sum;
        
    }
};
// code end here

// for testing

int main()
{
    Solution s;
    cout << s.reverse(1534236469) << endl;
}