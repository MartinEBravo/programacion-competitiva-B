#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
typedef long long ll;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ll> heroes(n+1);
        
        set<ll> bonus;
        map<ll,int> bonusCount;

        bonus.insert(0);

        for (int i = 0; i < n; i++){
            int x; cin >> x;
            // heroe
            if (x == 0){
                //maximum of set
                ll maxBonus = *bonus.rbegin();
                heroes[i] = maxBonus;
                // remove maxBonus

                if (bonusCount[maxBonus] == 1){
                    bonus.erase(maxBonus);
                    bonusCount[maxBonus] = 0;
                }
                else {
                    bonusCount[maxBonus]--;
                }

            }
            // bonus
            else {
                if (bonusCount[x] == 0){
                    bonus.insert(x);
                    bonusCount[x] = 0;
                }
                bonusCount[x]++;
            }
        }
        ll count = 0;
        for (int i = 0; i < heroes.size(); i++){
            count += heroes[i];
        }
        cout << count << endl;
    }
    return 0;
}