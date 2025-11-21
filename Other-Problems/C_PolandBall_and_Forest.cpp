/**                                            (⌐■_■)
*  Author :    zero_speed                       /█\   GG...
*  Created :   2025-11-19                      _/ \_ 
*  File :      C_PolandBall_and_Forest.cpp
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

void dfs(int u){
    visited[u]=true;
    for(auto v: adj[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}

void solve() {
    int n;
    cin>>n;

    visited.resize(n+1, false);
    adj.resize(n+1);

    for(int i=1;i<=n;i++){
        int u;
        cin>>u;
        adj[i].push_back(u);
        adj[u].push_back(i);
    }

    int ans=0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            ans++;
            dfs(i);
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