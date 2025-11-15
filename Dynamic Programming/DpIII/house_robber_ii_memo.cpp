#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int robLinearMemo(int i, int end, vector<int>& nums, vector<int>& memo) {
    if (i > end) return 0;
    if (memo[i] != -1) return memo[i];
    int rob_curr = nums[i] + robLinearMemo(i+2, end, nums, memo);
    int skip_curr = robLinearMemo(i+1, end, nums, memo);
    return memo[i] = max(rob_curr, skip_curr);
}

int rob2(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    vector<int> memo1(n, -1), memo2(n, -1);
    int excludeLast = robLinearMemo(0, n-2, nums, memo1);
    int excludeFirst = robLinearMemo(1, n-1, nums, memo2);
    return max(excludeLast, excludeFirst);
}

int main() {
    vector<int> nums = {2,3,2};
    cout << "House Robber II (memo): " << rob2(nums) << endl;
    return 0;
}
