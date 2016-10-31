/*
* author: dongchagnzhang
* mail: dongchang.zhang@outlook.com
* time: 2016.09
*/
#include <iostream>
#include <string>
#include <vector>


using namespace std;
// code from here
class Solution {
  public:
    /*
    * 输入整数
    * 返回该整数的罗马标示字符串
    */
    string intToRoman(int num) {
        vector<int> pos; // 提取num的每一位数字
        vector<int> fpos; // 存储对pos进行格式化后的数据，num的每一位占两位
        int tmp = num;
        // 提取num数字
        while (tmp != 0) {
            pos.push_back(tmp % 10);
            tmp /= 10;
        }
        // 对pos数组进行转化
        for (int i = pos.size() - 1; i != -1; --i) {
            // 一个一位的数字 如 1 2 4 9 最多需要两个字符表示
            // 假设每一个数字都需要用两个字符标示
            // 如 1 -> | |I| 4 -> |I|V| 6 -> |V|I|
            // 下面按上述表示法进行转化

            // 第一位
            if (pos[i] == 9) fpos.push_back(9); 
            else if (pos[i] >= 5) fpos.push_back(5);
            else if (pos[i] == 4) fpos.push_back(4);
            else fpos.push_back(0);
            // 第二位
            if (pos[i] > 8) fpos.push_back(9);
            else if(pos[i] >= 5) fpos.push_back(pos[i] - 5);
            else if(pos[i] == 4) fpos.push_back(4);
            else if(pos[i] <= 3) fpos.push_back(pos[i]);
        }
        string result = ""; // 存储罗马数字
        int n = fpos.size(); // 数字位数的两倍
        // 针对格式化后的数组进行解码
        for (int i = 0; i < fpos.size(); ++i) {
            // 对第一位解码

            if (fpos[i] == 9 || fpos[i] == 4) result += dict[8 - n + i][0]; 
            else if (fpos[i] == 5) result += dict[8 - n + i][1];
            // 第二位
            ++i;
            if (fpos[i] <= 3) for (int j = 0; j != fpos[i]; ++j) result += dict[8 - n + i][0];
            else if (fpos[i] == 9) result += dict[8 - n + i][2];
            else if (fpos[i] == 4) result += dict[8 - n + i][1];
        }
        return result;
    }

  private:
    // 存储罗马字符规则的字典 依次每两个vector标示一位数字
    vector<vector<string> > dict ={
        {},// 1
        {"M"},
        {"C", "D"},// 2
        {"C", "D", "M"},
        {"X", "L"},// 3
        {"X","L","C"},
        {"I", "V"},// 4
        {"I","V","X"}
    };
};
// code end here
int main() {
    Solution s;
    cout << s.intToRoman(3999) << endl;

}