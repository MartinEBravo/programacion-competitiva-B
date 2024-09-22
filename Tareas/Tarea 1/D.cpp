#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

int main() {
    ll n, x;
    cin >> n >> x;

    vector<ll> nums(n);
    map<ll, int> numIndexMap;


    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        numIndexMap[nums[i]] = i+1;
    }

    for (int i = 0; i< n; i++){
        ll numToFind = x - nums[i];
        if(numIndexMap.count(numToFind) && numIndexMap[numToFind] != i + 1) {
            cout << i+1 << " " << numIndexMap[numToFind] << endl;
            return 0;
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
