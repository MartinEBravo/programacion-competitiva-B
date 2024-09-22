#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

bool esPosible(ll a, ll b, ll x, ll k, ll n){
    ll energia_restante = k - (x * a);
    if (energia_restante <= 0) return false; 
    ll turnos_restantes = n - x; 
    return (turnos_restantes * b < energia_restante);
}

int main(){
    // Hacer que la entrada y salida de datos sea más rápida
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    // Lectura de datos
    int q; cin >> q;
    while(q--){

        // k: batería del computador
        // n: cantidad de turnos
        // b < a
        ll k, n, a, b; cin >> k >> n >> a >> b;


        // si k > a => su bateria disminuye en a
        // si a > k > b => su bateria disminuye en b
        // si k <= b => pierde el juego

        ll low = 0, high = n+1;
        ll result = -1;
        while (low < high){
            ll mid = (low + high)/2;

            if (esPosible(a, b, mid, k, n)){
                result = mid;
                low = mid+1;
            }
            else{
                high = mid;
            }

        }
        cout << result << endl;
    }
}