#include <iostream>
#include <vector>
using namespace std;

bool canJump(vector<int>& nums) {
    int farthest = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i > farthest) return false;
        farthest = max(farthest, i + nums[i]);
    }
    return true;
}

int main() {
    vector<int> nums = {2,3,1,1,4};
    cout << "Can jump to end? " << (canJump(nums) ? "Yes" : "No") << endl;
    return 0;
}
