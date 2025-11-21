/**                                            (⌐■_■)
*  Author :    zero_speed                       /█\   GG...
*  Created :   2025-11-19                      _/ \_ 
*  File :      D_Lunar_New_Year_and_a_Wander.cpp
**/
#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl "\n"
#define ll long long
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

vector<vector<int>> adj;
vector<bool>visited;
vector<int> ans;

void dfs(int u){
    visited[u]=true;
    ans.push_back(u);
    for(auto v: adj[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}

void solve() {
    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1);
    vector<bool> vis(n+1,false);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(1);

    vector<int> ans;

    while(!pq.empty()){
        int u = pq.top(); pq.pop();
        if(vis[u]) continue;
        vis[u] = true;

        ans.push_back(u);

        for(int v: adj[u])
            if(!vis[v]) pq.push(v);
    }

    for(int x: ans) cout << x << " ";
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