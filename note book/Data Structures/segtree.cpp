#include <bits/stdc++.h> // complexity: O(n log n) for build, O(log n) for update and query
using namespace std;

struct segtree{
    vector<int> tree;
    vector<int> lazy;
    int n;
    segtree(int n){
        this->n = n;
        tree.resize(4*n);
        lazy.resize(4*n, 0);
    }

    void build(vector<int>& arr, int node, int l, int r){
        if(l == r){
            tree[node] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(arr, 2*node, l, mid);
        build(arr, 2*node+1, mid+1, r);
        tree[node] = tree[2*node] + tree[2*node+1];
    }

    void push(int node, int l, int r){ // push the lazy updates to the children
        if(lazy[node] != 0){
            tree[node] += lazy[node] * (r - l + 1);
            if(l != r){
                lazy[2*node] += lazy[node];
                lazy[2*node+1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update(int node, int l, int r, int ql, int qr, int val){
        push(node, l, r);
        if(qr < l || ql > r) return;
        if(ql <= l && r <= qr){
            lazy[node] = val;
            push(node, l, r);
            return;
        }
        int mid = (l + r) / 2;
        update(2*node, l, mid, ql, qr, val);
        update(2*node+1, mid+1, r, ql, qr, val);
        tree[node] = tree[2*node] + tree[2*node+1];
    }

    int query(int node, int l, int r, int ql, int qr){
        push(node, l, r);
        if(qr < l || ql > r) return 0;
        if(ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return query(2*node, l, mid, ql, qr) + query(2*node+1, mid+1, r, ql, qr);
    }
};

int main(){

    int n,q;
    cin>>n>>q;
    segtree st(n);
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    st.build(arr, 1, 0, n-1);
    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int l,r,val;
            cin>>l>>r>>val;
            st.update(1, 0, n-1, l, r, val);
        }else{
            int l,r;
            cin>>l>>r;
            cout<<st.query(1, 0, n-1, l, r)<<endl;
        }
    }

    return 0;
}