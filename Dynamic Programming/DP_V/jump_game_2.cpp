#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int jump(vector<int>& nums) {
    int n = nums.size(), jumps = 0, end = 0, farthest = 0;
    for (int i = 0; i < n-1; i++) {
        farthest = max(farthest, i + nums[i]);
        if (i == end) {
            jumps++;
            end = farthest;
        }
    }
    return jumps;
}

int main() {
    vector<int> nums = {2,3,1,1,4};
    cout << "Minimum number of jumps: " << jump(nums) << endl;
    return 0;
}
