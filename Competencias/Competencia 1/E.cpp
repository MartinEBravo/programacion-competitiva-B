#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);

    ll n,x; cin >> n >> x;
    vector <ll> l(n);
    map<ll, int> numIndexMap;

    if (n<3){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++){
        cin >> l[i];
    }

    // encontrar 3 numeros que sumen x en l
    numIndexMap[l[0]] = 1;
    for (int i = 1; i < n-1; i++){
        for (int j = i+1; j < n; j++){

            ll numToFind = x - l[i] - l[j];
            if (numToFind < 0) continue;
            // Si el numero a encontrar es negativo, no existe
            // lo encontramos, y no es el mismo numero
            if (numIndexMap.find(numToFind) != numIndexMap.end()){
                cout << i+1 << " " << j+1 << " " << numIndexMap[numToFind] << endl;
                return 0;
            }
        }
        numIndexMap[l[i]] = i+1;
    }
    
    

    cout << "IMPOSSIBLE" << endl;
    return 0;
}