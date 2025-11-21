/**                                            (⌐■_■)
*  Author :    zero_speed                       /█\   GG...
*  Created :   2025-11-19                      _/ \_ 
*  File :      C_Cut_em_all.cpp
**/
#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl "\n"
#define ll long long
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

vector<vector<int>> adj;
vector<bool> visited;

int ans = 0;

int dfs(int u){
    visited[u] = true;
    int tam = 1;       
    
    for(int v : adj[u]){
        if(!visited[v]){
            int sub = dfs(v);
            if(sub % 2 == 0){
                ans++;        
            } else {
                tam += sub;  
            }
        }
    }

    return tam;
}

void solve() {
    int n;
    cin>>n;
    visited.resize(n+1, false);
    adj.resize(n+1);
    for(int i=0;i+1<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(n%2){
        cout<<-1<<endl;
        return;
    }
    dfs(1);
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