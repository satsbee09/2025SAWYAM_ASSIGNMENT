#include <iostream>
#include <vector>
using namespace std;

int change(int amount, vector<int>& coins) {
    vector<int> dp(amount+1, 0);
    dp[0] = 1;
    for (int c : coins)
        for (int i = c; i <= amount; i++)
            dp[i] += dp[i - c];
    return dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 5;
    cout << "Ways to make change: " << change(amount, coins) << endl;
    return 0;
}
