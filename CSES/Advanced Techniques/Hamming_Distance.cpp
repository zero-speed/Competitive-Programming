/**                                            (⌐■_■)
*  Author :    zero_speed                       /█\   GG...
*  Created :   2025-11-18                      _/ \_ 
*  File :      Hamming_Distance.cpp
**/
#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl "\n"
#define ll long long
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

void solve() {
    int n,m;
    cin>>n>>m;
    vector<ll> a(n,0);
    unordered_set<ll> aux;
    vector<vector<int>> conta(m+1);
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        ll x=0;
        for (int j = 0; j < m; j++){
            if (s[j] == '1') {
                x |= (1LL << j);
            }
        }

        a[i]=x;
        aux.insert(x);
        conta[__builtin_popcountll(x)].push_back(x);
    }

    if(aux.size()<n){
        cout<<0<<endl;
        return;
    }

    ll ans=m;

    for(int i=0;i<=m;i++){
        for(int j=i;j<=m;j++){
            
            int hola=abs(i-j);
            if(hola>=ans) continue;
            for(auto x : conta[i]){
                for(auto y : conta[j]){
                    if(x==y) continue;
                    ll bits=__builtin_popcountll(x^y);
                    //cout<<bits<<endl;
                    ans=min(ans, bits);
                }
            }


        }
    }
    cout<<ans<<endl;


}

int main() {
    fastio;
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}