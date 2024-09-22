#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[501][501];
int INF = 1e9;

int solve(int a, int b){
    if (a > b) swap(a,b);
    if(a == b) return dp[a][b] = 0;
    if(dp[a][b] != INF) return dp[a][b];
    if (a == 1) return dp[a][b] = b-1;
    if (b == 1) return dp[a][b] = a-1;
    for (int i = 1; i < a; i++){
        dp[a][b] = min(dp[a][b], solve(i,b) + solve(a-i,b) + 1);
    }
    for (int i = 1; i < b; i++){
        dp[a][b] = min(dp[a][b], solve(a,i) + solve(a,b-i) + 1);
    }
    return dp[a][b];

}

int main(){
    int a,b;
    cin >> a >> b;
    for (int i = 0; i < 501; i++){
        for (int j = 0; j < 501; j++){
            dp[i][j] = INF;
        }
    }
    cout << solve(a,b) << endl;

}