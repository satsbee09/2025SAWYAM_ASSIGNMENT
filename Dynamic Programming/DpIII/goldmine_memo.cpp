#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int goldMemo(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& memo) {
    int n = grid.size(), m = grid[0].size();
    if (i<0 || i>=n || j>=m) return 0;
    if (memo[i][j] != -1) return memo[i][j];
    int right = goldMemo(i, j+1, grid, memo);
    int right_up = goldMemo(i-1, j+1, grid, memo);
    int right_down = goldMemo(i+1, j+1, grid, memo);
    return memo[i][j] = grid[i][j] + max({right, right_up, right_down});
}

int getMaxGoldMemo(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size(), ans = 0;
    vector<vector<int>> memo(n, vector<int>(m, -1));
    for (int i=0; i<n; i++) ans = max(ans, goldMemo(i, 0, grid, memo));
    return ans;
}

int main() {
    vector<vector<int>> grid = { {10,33,13,15}, {22,21,04,1}, {5,0,2,3}, {0,6,14,2} };
    cout << "Max Gold mine (memo): " << getMaxGoldMemo(grid) << endl;
    return 0;
}
