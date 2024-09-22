#include <string>
#include <vector>
#include <iostream>


using namespace std;

struct segment_tree{

  int N;
  vector <int> tree;
  
  segment_tree(vector <int> &A){
    // constructor
    N = A.size();
    tree.resize(4*N);
    build(0, 0, N-1, A);
  }

  int merge(int a, int b){
    return a+b;
  }

  void build(int n, int i, int j, vector <int> &A){
    // n: indice del nodo
    // nodo mira segmento [i,j]
    if(i == j){
      tree[n] = A[i];
      return;
    }
    int mid = (i+j)/2;
    // hijo izq: 2n+1
    // hijo der: 2n+2
    build(2*n+1, i, mid, A);
    build(2*n+2, mid+1, j, A);
    tree[n] = merge(tree[2*n+1], tree[2*n+2]);
  }

  int query(int l, int r){
    return query(0, 0, N-1, l, r);
  }

  int query(int n, int i, int j, int l, int r){
    // nodo actual mira intervalo [i,j]
    // queremos responder consulta [l,r]
    // caso 1: contenido totalmente
    if(l <= i && j <= r){
      return tree[n];
    }
    // caso 2: [i,j] está fuera de [l,r]
    if(j < l || r < i){
      return 0;
    }
    // caso 3: contenido parcialmente
    int mid = (i+j)/2;
    return merge(query(2*n+1, i, mid, l, r),query(2*n+2, mid+1, j, l, r));
  }

  void update(int idx, int x){
    // A[idx] = x
    update(0, 0, N-1, idx, x);
  }

  void update(int n, int i, int j, int idx, int x){
    // no contiene a idx
    if(idx < i || idx > j){
      return;
    }
    if(i == j){
      tree[n] = x;
      return;
    }
    int mid = (i+j)/2;
    update(2*n+1, i, mid, idx, x);
    update(2*n+2, mid+1, j, idx, x);
    tree[n] = merge(tree[2*n+1], tree[2*n+2]);
  }
};

int main(){
    int N; cin >> N;
    vector <int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    segment_tree st(A);
    int Q; cin >> Q;
    while (Q--){
        string s; cin >> s;
        if (s == "Q"){
            int x, y; cin >> x >> y;
            cout << st.query(x-1, y-1) << endl;
        } else {
            int i, x; cin >> i >> x;
            st.update(i-1, x);
        }
    }

  return 0;
}
