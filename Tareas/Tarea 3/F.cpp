#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
typedef long long ll;


// busca si las letras h y a y r y d estan en el string
// bool estaHard(string string){
//     map<char, int> m;
//     m['h'] = 0;
//     m['a'] = 0;
//     m['r'] = 0;
//     m['d'] = 0;
//     for(int i = 0; i < string.size(); i++){
//         if(string[i] == 'h' || string[i] == 'a' || string[i] == 'r' || string[i] == 'd'){
//             m[string[i]]++;
//         }
//     }
//     if(m['h'] >= 1 && m['a'] >= 1 && m['r'] >= 1 && m['d'] >= 1){
//         return true;
//     }
//     else{
//         return false;
//     }
// }

ll mymin(ll a, ll b){
    if(a < b){
        return a;
    }
    else{
        return b;
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll n; cin >> n;
    string s; cin >> s;
    vector<ll> a(n);
    ll H = 0, A = 0, R = 0, D = 0;

    for (int i = 0; i < n; i++) cin >> a[i];

    for(int i = 0; i < n; i++){
        if (s[i] == 'h') H+=a[i];
        if (s[i] == 'a') A=mymin(H, A+a[i]);
        if (s[i] == 'r') R=mymin(A, R+a[i]);
        if (s[i] == 'd') D=mymin(R, D+a[i]);
    }
    cout << D << endl;
}