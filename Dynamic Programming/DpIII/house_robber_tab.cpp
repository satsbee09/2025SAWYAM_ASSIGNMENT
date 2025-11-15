#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rob_tab(const vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    vector<int> dp(n+1, 0);
    dp[n-1] = nums[n-1];
    for (int i = n-2; i>=0; i--)
        dp[i] = max(nums[i] + (i+2<n ? dp[i+2] : 0), dp[i+1]);
    return dp[0];
}

int main() {
    vector<int> nums = {1,2,3,1};
    cout << "Maximum rob (tab): " << rob_tab(nums) << endl;
    return 0;
}
