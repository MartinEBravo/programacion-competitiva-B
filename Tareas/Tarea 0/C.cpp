#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int main(){
    string s; cin >> s;
    int n = s.size();
    string alf = "abcdefghijklmnopqrstuvwxyz";
    string salio = "";
    int count = 0;
    for (int i = 0; i < n; i++){
        // Sale una palabra por primera vez
        if (s[i] == alf[count]){
            salio += s[i];
            count++;
        }
        // Sale una palabra que ya salio s[i] in salio
        else if (salio.find(s[i]) != string::npos){
            continue;
        }
        // Sale una palabra que no es la siguiente
        else{
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
