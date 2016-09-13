#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        vector<string> tmp;
        for (auto ch : digits) {
            if (result.size() == 0) {
                for (auto letter : dict.find(ch)->second) {
                    tmp.push_back(string(1,letter));
                }
            }
            else {
                for (auto key : result) {
                    for (auto letter : dict.find(ch)->second) {
                        tmp.push_back(key + string(1,letter));
                    }
                }
            }
            result = tmp;
            tmp.clear();
        }
        return result;
    }
private:
    map<char, string> dict = {
        pair<char, string> ('2', "abc"),
        pair<char, string> ('3', "def"),
        pair<char, string> ('4', "ghi"),
        pair<char, string> ('5', "jkl"),
        pair<char, string> ('6', "mno"),
        pair<char, string> ('7', "pqrs"),
        pair<char, string> ('8', "tuv"),
        pair<char, string> ('9', "wxyz")
    };
};

int main() 
{
    Solution s;
    for (auto r : s.letterCombinations("23"))
        cout << r << endl;
}