/*
* author: dongchagnzhang
* mail: dongchang.zhang@outlook.com
* time: 2016.09.10
*/
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
     string longestCommonPrefix(vector<string>& strs) {
        int index = 0;
        string prefix = "";
        bool is_prefix = true;
        bool finished = false;
        if (strs.size() == 0) return "";
        else {
            while (!finished) {
                if (strs[0].size() <= index) finished = true;
                else {
                    char ch = strs[0][index];
                    for (int i = 1; i != strs.size(); ++i) {
                        if (ch != strs[i][index]) {
                            is_prefix = false;
                            finished = true;
                            break;
                        }
                    }
                    if (is_prefix) {
                        prefix += ch;
                    }
                }
                ++index;
            }
        }
        return prefix; 
    }
};

int main()
{
    Solution s;
    string s1 = "lalaladongchang";
    string s2 = "lalahahahadsfhds";
    string s3 = "lalahaasdfkljl";
    vector<string> vs = {s1, s2, s3};
    cout << s.longestCommonPrefix(vs) << endl;
    return 0;
}