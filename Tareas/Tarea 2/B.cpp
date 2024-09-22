#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

// Función que determina si es posible armar k subarreglos con suma minima mid
bool esPosible(vector<ll> &suma, ll sumaMinima, int k, int n) {
    int subarreglos = 0;
    ll sumaActual = 0;
    
    for (int i = 0; i < n; i++) {
        if (suma[i] > sumaMinima) {
            return false;
        }
        if (sumaActual + suma[i] > sumaMinima) {
            subarreglos++;
            sumaActual = 0;
        }
        sumaActual += suma[i];
    }

    // Si al final del bucle aún hay suma acumulada, cuenta un subarreglo más
    if (sumaActual > 0) {
        subarreglos++;
    }

    return subarreglos <= k;
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    // Lectura de datos
    int n,k; cin >> n >> k;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    // Calculo de la suma acumulada
    // vector<ll> suma(n);
    // suma[0] = a[0];
    // for(int i=1;i<n;i++) suma[i] = suma[i-1] + a[i];

    // Calculo del minimo
    // ll minA = 1e18;
    // for(int i=0;i<n;i++) minA = min(minA, a[i]);


    // Busqueda Binaria
    ll low = 1, high = 1e18;
    while (low < high){
        // Vamos a buscar el menor valor tal que sea posible armarlo con k subarreglos
        ll mid = (low + high)/2;
        if (esPosible(a, mid, k, n)){
            high = mid;
        }
        else{
            low = mid+1;
        }
    }

    cout << low << endl;

    // ll minimo = 1e18;

    // i largo del primer sub arreglo
    // for (int i = 0; i < n-k+1; i++){
        // j largo del segundo sub arreglo
        // for (int j = i+1; j < n-k+2;j++){
            // minimo = min(minimo, max(suma[i], max(suma[j]-suma[i], suma[n-1]-suma[j])));
        // }
    // }
    // cout << minimo << endl;
}