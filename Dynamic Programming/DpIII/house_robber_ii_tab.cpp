#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int robTabulation(vector<int>& nums, int start, int end) {
    int n = end-start+1;
    vector<int> dp(n+2, 0);
    for (int i=end; i>=start; i--) {
        dp[i-start] = max(nums[i] + ((i+2<=end) ? dp[i-start+2] : 0),
                          ((i+1<=end) ? dp[i-start+1] : 0));
    }
    return dp[0];
}

int rob2(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    int excludeLast = robTabulation(nums, 0, n-2);
    int excludeFirst = robTabulation(nums, 1, n-1);
    return max(excludeLast, excludeFirst);
}

int main() {
    vector<int> nums = {2,3,2};
    cout << "House Robber II (tab): " << rob2(nums) << endl;
    return 0;
}
