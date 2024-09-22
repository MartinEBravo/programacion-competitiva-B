#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    // vamos a guardar acá 
    vector<int> b(n, 1);

    for (int i = 1; i < n; i++){
        if (a[i] - a[i-1] <= x){
            b[i] = b[i-1] + 1;
        }
    }
    sort(b.begin(), b.end());
    cout << b[n-1] << endl;
}
