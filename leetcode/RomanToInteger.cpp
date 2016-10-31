/*
* author: dongchagnzhang
* mail: dongchang.zhang@outlook.com
* time: 2016.09
*/
#include<iostream>
#include<string>
#include<map>

using namespace std;
// code from here
class Solution {
public:
    int romanToInt(string s) {
        // 如果下一个字符代表的数字大于当前的字符代表的数字则在总和中减去这个值
        // 否则加上这个值
        int sum = 0;
        for (int i = 0; i != s.size(); ++i) {
            if (i + 1 != s.size()) {
                if (dict.find(s[i])->second >= dict.find(s[i + 1])->second) {
                    sum += dict.find(s[i])->second;
                }
                else {
                    sum -= dict.find(s[i])->second;
                }
            }
            else {
                sum += dict.find(s[i])->second;
            }
        }
        return sum;
    }
private:
    const map<char, int> dict {
        pair<char, int> ('M', 1000),
        pair<char, int> ('D', 500),
        pair<char, int> ('C', 100),
        pair<char, int> ('L', 50),
        pair<char, int> ('X', 10),
        pair<char, int> ('V', 5),
        pair<char, int> ('I', 1),
    };
};
// code end here
int main()
{
    Solution s;
    string str = "MMMCMXCIX";
    cout << s.romanToInt(str) << endl;
    return 0;
}