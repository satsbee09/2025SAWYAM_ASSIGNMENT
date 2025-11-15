#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Returns true if s matches p (with '.' and '*')
bool isMatch(const string& s, const string& p) {
    int m = s.length(), n = p.length();
    vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
    dp[0][0] = true;

    // patterns like a*, a*b*, a*b*c* at the start can match an empty string
    for (int j = 2; j <= n; j++)
        if (p[j-1] == '*')
            dp[0][j] = dp[0][j-2];

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j-1] == '.' || s[i-1] == p[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else if (p[j-1] == '*') {
                dp[i][j] = dp[i][j-2];
                if (p[j-2] == '.' || p[j-2] == s[i-1])
                    dp[i][j] = dp[i][j] || dp[i-1][j];
            }
        }
    }
    return dp[m][n];
}

int main() {
    string s1 = "aab", p1 = "c*a*b";
    string s2 = "mississippi", p2 = "mis*is*p*.";
    cout << "Match 1? " << (isMatch(s1, p1) ? "Yes" : "No") << endl;
    cout << "Match 2? " << (isMatch(s2, p2) ? "Yes" : "No") << endl;
    return 0;
}
