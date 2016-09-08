/*
* author: dongchagnzhang
* mail: dongchang.zhang@outlook.com
* time: 2016.09.08
*/
#include<string>
#include<vector>
#include<iostream>
#define INT_MAX 2147483647
#define INT_MIN -2147483648
using namespace std;

// code from here
class Solution {
public:
    /*
    * 超出界限 返回界限，错误数据返回0
    * 忽略前面空格
    * 处理数字开始的正负号
    * 以非数字开始为错误数据
    * 处理数字过程中遇到非数字字符返回当前结果
    */
    int myAtoi(string str) {
        str = formatStr(str); // 去除空格
        long long sum = 0; // 返回结果
        if (str.empty()) sum = 0; // 空字符串
        else if (str[0] == '-' || str[0] == '+' || 
                (str[0] >= '0' && str[0] <= '9')) { // 是数字
            int begin = 0;
            if (str[0] == '-' || str[0] == '+')
                begin = 1;
            for(int i = begin; i != str.size(); ++i) {
                if (str[i] >= '0' && str[i] <= '9') {
                    sum = sum * 10 + (int)(str[i] - '0');
                    if (sum > -INT_MIN) { // 溢出马上跳出
                        break;
                    }
                }
                else break;
            }
            // 负数
            if (str[0] == '-') sum = -sum;
            // 上溢
            if (sum > INT_MAX) {
                sum = INT_MAX; 
            }
            // 下溢
            else if (sum < INT_MIN) {
                sum = INT_MIN;
            }
        }
        else
            sum = 0;
        return sum;
    }
    // 去除首尾空格
    string formatStr(string str) {
        str.erase(0, str.find_first_not_of(" "));
        str.erase(str.find_last_not_of(" ") + 1);
        return str;
    }
};
// end here
int main()
{
    Solution s;
    string str = "9223372036854775809";
     string strs = "123";
    cout << s.myAtoi(str) << endl;
}