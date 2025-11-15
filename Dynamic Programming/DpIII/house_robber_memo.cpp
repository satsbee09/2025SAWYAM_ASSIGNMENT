#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rob_memo(int i, vector<int>& nums, vector<int>& memo) {
    if (i >= (int)nums.size()) return 0;
    if (memo[i] != -1) return memo[i];
    int rob_curr = nums[i] + rob_memo(i+2, nums, memo);
    int skip_curr = rob_memo(i+1, nums, memo);
    return memo[i] = max(rob_curr, skip_curr);
}

int main() {
    vector<int> nums = {1,2,3,1};
    vector<int> memo(nums.size(), -1);
    cout << "Maximum rob (memo): " << rob_memo(0, nums, memo) << endl;
    return 0;
}
