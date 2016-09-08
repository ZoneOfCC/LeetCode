/*
* author: dongchagnzhang
* mail: dongchang.zhang@outlook.com
* time: 2016.09
*/
#include<iostream>
#include<string>
#include<vector>

using namespace std;

// code from here
class Solution {
public:
    string convert(string s, int numRows) {
        string result; // 返回的结果
        vector<string> lines(numRows, ""); // 将每一行存入相应的vector，vector[0]对应最高的行
        if (numRows == 1) // 只有一行
            return s;
        else { // 多行
            int times = 0; // 用于遍历字符串s的索引变量
            bool finish = false; // 判断是否到达字符串结尾
            while (1) {
                // 从最高行到最低航
                for (int line = 0; line != numRows; ++line) {
                    lines[line] += s[times++];
                    if (times >= s.size()) {
                        finish = true;
                        break;
                    }
                }
                if (finish) break;
                // 从最低位置返回最低位置
                for (int line = numRows - 2; line > 0; --line) {
                    lines[line] += s[times++];
                    if (times >= s.size()) {
                        finish = true;
                        break;
                    }
                }
                if (finish) break;
            }
        }
        // 将字符串拼接
        for (auto line : lines) {
            result += line;
        }
        return result;
    }
};

// end here

// for test
int main()
{
    Solution s;
    string str = "PAYPALISHIRING";
    cout << s.convert(str, 3) << endl;
    return 0;
}