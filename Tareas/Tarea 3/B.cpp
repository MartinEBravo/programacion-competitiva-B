#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll MOD = 1e9 +7;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<vector<char> > grilla(n, vector<char>(n));
    vector<vector<int> > dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> grilla[i][j];
        }
    }

    if (grilla[0][0] != '*') {
        dp[0][0] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grilla[i][j] == '*') continue;
            if (i > 0) dp[i][j] += dp[i-1][j] % MOD;
            if (j > 0) dp[i][j] += dp[i][j-1] % MOD;
        }
    }

    cout << dp[n-1][n-1] % MOD << endl;

    return 0;
}
