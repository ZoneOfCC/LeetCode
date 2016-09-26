class Solution {
public:
    bool isValid(string s) {
        stack<char> pool;
        for (auto ch : s) {
            if (pool.size() == 0) {
                pool.push(ch);
                
            }
            else if (dict[pool.top()] == ch) {
                pool.pop();
            }
            else {
                pool.push(ch);
            }
        }
        return (pool.size() == 0);
    }
private:
    map<char,char> dict{
        pair<char, char> ('(', ')'),
        pair<char, char> (')', '('),
        pair<char, char> ('[', ']'),
        pair<char, char> (']', '['),
        pair<char, char> ('{', '}'),
        pair<char, char> ('}', '{')
    };
};