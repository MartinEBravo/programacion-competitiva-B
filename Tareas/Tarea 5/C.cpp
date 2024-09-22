#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
typedef long long ll;


int main() {
    string s, n;
    getline(cin, s);
    getline(cin, n);

    int ans = 0;
    size_t pos = 0;

    while ((pos = s.find(n, pos)) != string::npos) {
        ans++;
        pos += n.length();
    }

    cout << ans << endl;
    return 0;
}