class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        
        execute(result, "", "(", n, 1, 0);
        return result;
        
        
    }
    void execute(vector<string> &result, string tmp, string next, int n, int l, int r) {
        tmp += next;
        if (l < r || l > n || r > n) return;
        if (l == n && r == n) {
            result.push_back(tmp);
            return;
        }
        execute(result, tmp, "(", n, l + 1, r);
        execute(result, tmp, ")", n, l, r + 1);
        
    }
};