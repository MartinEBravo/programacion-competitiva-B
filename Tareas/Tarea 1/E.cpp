#include <iostream>
#include <set>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int x, n;
    cin >> x >> n;

    set<int> semaforos; 
    multiset<int> distancias;

    semaforos.insert(0);
    semaforos.insert(x);
    distancias.insert(x);

    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;

        auto it = semaforos.lower_bound(p);
        int right = *it;
        int left = *(--it);

        distancias.erase(distancias.find(right - left));
        distancias.insert(p - left); 
        distancias.insert(right - p); 

        semaforos.insert(p);
        
        cout << *(--distancias.end()) << " ";

    }

    return 0;
}
