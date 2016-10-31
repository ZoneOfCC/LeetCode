/*
* author: dongchagnzhang
* mail: dongchang.zhang@outlook.com
* time: 2016.09
*/
#include<string>
#include<iostream>

using namespace std;

// code from here
class Solution {
public:
    /*
    * 传入一个c++类型的字符串
    * 返回一个最长的回文子串
    */
    string longestPalindrome(const string &s) {
        string stmp = formatString(s); // 向字符串的每个字符之间添加空格
        string substr = ""; // 需要返回的结果字符串
        // 遍历格式化后的字符串，以每个字符为中心判断最长回文字符串
        for (int i = 0; i != stmp.size(); ++i) {
            string tmp = findPalindrome(stmp, i);
            if (tmp.size() > substr.size()) {
                substr = tmp;
            }
        }
        return substr;
    }
    /*
    * 传入一个字符串
    * 返回将传入字符串的所有字符之间添加空格，包括开头结尾的字符串
    */
    string formatString(const string &s) {
        string result = " ";
        for(int i = 0; i != s.size(); ++i) {
            result += s[i];
            result += ' ';
            
        }  
        return result;
    }
    /*
    * 传入字符串和一个整数（大于0小于该字符串的长度）
    * 以location为中心判断回文子串（奇数长)
    * 返回子串
    */
    string findPalindrome(const string &s, int location) {
        string pstring = ""; // 需要返回的目的回文串
        int loc = 0; // 一个向两边扩展的游标
        // 以location为中心向两边扩展，寻找回文串
        while (location - loc >= 0 && location + loc < s.size()) {
            if (s[location - loc] == s[location + loc]) {
                ++loc;
            }
            else {
                break;
            }
        }
        // 失败时loc多增加了1，现在减去
        --loc;
        string tmp = ""; // 存储格式化后的最大回文串
        for (int i = location - loc; i != location + loc + 1; ++i) {
            tmp += s[i];
        }
        // 去除空格
        for (auto ch : tmp) {
            if (ch != ' ') pstring += ch; 
        }
        return pstring;
    }
};
// end here

int main() {
    Solution s;
    string str = "";
    cout << s.longestPalindrome(str) << endl; 
}