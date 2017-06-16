class Solution {
public:
    string reverseWords(string s) {
        bool start = true;
        istringstream is(s);
        string tmp, r;
        while (is >> tmp) {
            if (!start) {
                r += ' ';
            } else {
                start = false;
            }
            for (auto it = tmp.rbegin(); it != tmp.rend(); ++it) {
                r += *it;
            }
        }
        return r;
    }
};