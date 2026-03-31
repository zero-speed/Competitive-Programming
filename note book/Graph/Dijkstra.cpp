#include <bits/stdc++.h> // complexity: O((V+E) log V)

using namespace std;
#define INF 1e9
#define MAXN 100005
#define ll long long

vector<pair<int, ll>> adj[MAXN];
vector<ll> dis(MAXN, INF);
void dijkstra(int n, int start){
    //priority_queue<TIPO, CONTENEDOR, COMPARADOR>
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    dis[start] = 0;
    pq.push({0, start});
    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();
        if(d > dis[u]) continue;
        for(auto [v, w] : adj[u]){
            if(dis[u] + w < dis[v]){
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }
}

int main(){
    int n, m, start;
    cin >> n >> m >> start;
    for(int i = 0; i < m; i++){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Si el grafo es no dirigido
    }
    dijkstra(n, start);
    for(int i=1;i<=n;i++){
        cout<<start<<"->"<<i<<": "<<dis[i]<<endl;
        // 2->1: 10
        // 2->2: 0
        // 2->3: 5
        // 2->4: 15
    }
    return 0;
}