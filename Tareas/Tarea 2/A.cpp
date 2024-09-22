#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,t; cin >> n >> t;
    vector <ll> numeros(n);
    for (int i = 0; i < n; i++){
        cin >> numeros[i];
    }
    ll tiempo_min = 1;
    ll tiempo_max = 1e18;

    ll result;

    while (tiempo_min <= tiempo_max){
        ll mid = (tiempo_min + tiempo_max) / 2;
        ll suma = 0;
        for (int i = 0; i < n; i++){
            suma += (mid / numeros[i]);
            if (suma >= t){
                break;
            }
        }
        if (suma >= t){
            result = mid;
            tiempo_max = mid-1;
        }else{
            tiempo_min = mid+1;
        }

    }
    cout << result << endl;
}