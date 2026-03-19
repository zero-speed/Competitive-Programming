#include <bits/stdc++.h>
using namespace std;

struct segtree{
    vector<int> arbol;
    vector<int> valores;
    int n;
    segtree(int n){
        this->n = n;
        arbol.resize(4*n);
        valores.resize(n);
    }

    void init(int l, int r, int nodo){
        if(l==r){
            arbol[nodo] = valores[l];
            return;
        }
        int mid = (l+r)/2;
        init(l, mid, 2*nodo);
        init(mid+1, r, 2*nodo+1);
        arbol[nodo] = arbol[2*nodo] + arbol[2*nodo+1];
    }

    void update(int l, int r, int nodo, int pos, int val){
        if(l==r){
            arbol[nodo] = val;
            return;
        }
        int mid = (l+r)/2;
        if(pos<=mid) update(l, mid, 2*nodo, pos, val);
        else update(mid+1, r, 2*nodo+1, pos, val);
        arbol[nodo] = arbol[2*nodo] + arbol[2*nodo+1];
    }

    int query(int l, int r, int nodo, int ql, int qr){
        if(qr<l || ql>r) return 0;
        if(ql<=l && r<=qr) return arbol[nodo];
        int mid = (l+r)/2;
        return query(l, mid, 2*nodo, ql, qr) + query(mid+1, r, 2*nodo+1, ql, qr);
    }
}

int main(){

    int n,q;
    cin>>n>>q;
    segtree st(n);
    for(int i=0; i<n; i++) cin>>st.valores[i];
    st.init(0, n-1, 1);
    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int pos, val;
            cin>>pos>>val;
            st.update(0, n-1, 1, pos, val);
        }else{
            int l,r;
            cin>>l>>r;
            cout<<st.query(0, n-1, 1, l, r)<<endl;
        }
    }

    return 0;
}