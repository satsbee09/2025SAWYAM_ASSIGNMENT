#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getMaxGoldTab(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i=0; i<n; i++) dp[i][m-1] = grid[i][m-1];
    for (int j=m-2; j>=0; j--) {
        for (int i=0; i<n; i++) {
            int right = dp[i][j+1];
            int right_up = i>0 ? dp[i-1][j+1] : 0;
            int right_down = i<n-1 ? dp[i+1][j+1] : 0;
            dp[i][j] = grid[i][j] + max({right, right_up, right_down});
        }
    }
    int maxGold = 0;
    for (int i=0; i<n; i++) maxGold = max(maxGold, dp[i][0]);
    return maxGold;
}

int main() {
    vector<vector<int>> grid = { {10,33,13,15}, {22,21,04,1}, {5,0,2,3}, {0,6,14,2} };
    cout << "Max Gold mine (tab): " << getMaxGoldTab(grid) << endl;
    return 0;
}
