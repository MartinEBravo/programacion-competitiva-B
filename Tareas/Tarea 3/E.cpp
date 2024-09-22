#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    vector<int> dp(n+1, -1);

    dp[0] = 0; // base case

    for (int i = 1; i <= n; i++) {
        if (a <= i && dp[i-a] != -1) {
            dp[i] = max(dp[i], dp[i-a] + 1);
        }
        if (b <= i && dp[i-b] != -1) {
            dp[i] = max(dp[i], dp[i-b] + 1);
        }
        if (c <= i && dp[i-c] != -1) {
            dp[i] = max(dp[i], dp[i-c] + 1);
        }
    }

    cout << dp[n] << endl;
    return 0;
}