#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dfs(vector<vector<int>>& grid, int r, int c, vector<vector<bool>>& visited) {
    if (r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || grid[r][c]==0 || visited[r][c]) return 0;
    visited[r][c] = true;
    int maxGold = 0;
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    for (int d=0; d<4; d++)
        maxGold = max(maxGold, dfs(grid, r+dirs[d][0], c+dirs[d][1], visited));
    visited[r][c] = false;
    return grid[r][c] + maxGold;
}

int getMaximumGold(vector<vector<int>>& grid) {
    int ans = 0;
    int n = grid.size(), m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if (grid[i][j])
                ans = max(ans, dfs(grid, i, j, visited));
    return ans;
}

int main() {
    vector<vector<int>> grid = { {0,6,0}, {5,8,7}, {0,9,0} };
    cout << "Max Gold path: " << getMaximumGold(grid) << endl;
    return 0;
}
