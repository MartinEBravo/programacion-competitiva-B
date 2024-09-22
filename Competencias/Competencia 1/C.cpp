#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long int ll;

int main(){
    cin.tie(0);ios::sync_with_stdio(false);

    ll n; cin >> n;

    vector <pair <ll,ll> > s(n);

    for (int i = 0; i < n; i++){
        int a,b; cin >> a >> b;
        s[i] = make_pair(a,b);
    }

    // ordenar segun a, si son iguales, ordenar segun b
    sort(s.begin(), s.end());


    // utilidad total
    ll sum = 0;
    // tiempo actual
    ll tiempo = 0;
    for (int i = 0; i < n; i++){
        ll utilidad = s[i].second - s[i].first - tiempo;
        tiempo += s[i].first;
        sum += utilidad;
    }
    cout << sum << endl;
    return 0;
}