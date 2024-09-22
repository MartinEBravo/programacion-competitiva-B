#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

struct segment_tree{

    int N;
    vector <int> tree;
  
    segment_tree(vector <int> &A){
        // constructor
        N = A.size();
        tree.resize(4*N);
        build(0, 0, N-1, A, 0);
    }

    int merge(int a, int b, int level){
        if (level % 2 == 0) return a^b;
        else return a | b;
    }

    void build(int n, int i, int j, vector <int> &A,int level){
        // n: indice del nodo
        // nodo mira segmento [i,j]
        if(i == j){
            tree[n] = A[i];
            return;
        }
        int mid = (i+j)/2;
        // hijo izq: 2n+1
        // hijo der: 2n+2
        build(2*n+1, i, mid, A, level+1);
        build(2*n+2, mid+1, j, A, level+1);
        tree[n] = merge(tree[2*n+1], tree[2*n+2], level);
    }

    int query(int l, int r){
        return query(0, 0, N-1, l, r, 0);
    }

    int query(int n, int i, int j, int l, int r, int level){
        // nodo actual mira intervalo [i,j]
        // queremos responder consulta [l,r]
        // caso 1: contenido totalmente
        if(l <= i && j <= r){
            return tree[n];
        }
        // caso 2: [i,j] está fuera de [l,r]
        if(j < l || r < i){
            return (level % 2 == 0) ? 0 : INT_MAX;
        }
        // caso 3: contenido parcialmente
        int mid = (i+j)/2;
        return merge(query(2*n+1, i, mid, l, r, level+1), query(2*n+2, mid+1, j, l, r, level+1), level);
    }

    void update(int idx, int x){
        // A[idx] = x
        update(0, 0, N-1, idx, x, 0);
    }

    void update(int n, int i, int j, int idx, int x, int level){
        // no contiene a idx
        if(idx < i || idx > j){
            return;
        }
        if(i == j){
            tree[n] = x;
            return;
        }
        int mid = (i+j)/2;
        update(2*n+1, i, mid, idx, x, level+1);
        update(2*n+2, mid+1, j, idx, x, level+1);
        tree[n] = merge(tree[2*n+1], tree[2*n+2], level);
    }
};

int main(){
    int n,m; cin >> n >> m;
    vector <int> a(pow(2,n));
    for(int i = 0; i < pow(2,n); ++i) cin >> a[i];
    segment_tree st(a);
    while (m--){
        int i, x;
        cin >> i >> x;
        st.update(i-1, x);
        cout << st.query(0, pow(2,n)-1) << endl;
    }
}
