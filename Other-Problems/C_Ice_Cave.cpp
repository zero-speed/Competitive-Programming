/**                                            (⌐■_■)
*  Author :    zero_speed                       /█\   GG...
*  Created :   2025-11-19                      _/ \_ 
*  File :      C_Ice_Cave.cpp
**/
#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl "\n"
#define ll long long
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

int n, m;
vector<string> g;
vector<vector<int>> vis;
int sx, sy, fx, fy;

bool ok(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y) {
    vis[x][y] = 1;
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};

    for(int k = 0; k < 4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if(!ok(nx,ny)) continue;
        if(!vis[nx][ny] && (g[nx][ny] == '.' || (nx == fx && ny == fy))) {
            dfs(nx, ny);
        }
    }
}

int main() {
    cin >> n >> m;
    g.resize(n);
    for(int i = 0; i < n; i++) cin >> g[i];
    cin >> sx >> sy >> fx >> fy;
    sx--, sy--, fx--, fy--;
    vis.assign(n, vector<int>(m, 0));
    dfs(sx, sy);

    if(!vis[fx][fy]) {
        cout << "NO\n";
        return 0;
    }
    int cnt = 0;
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};

    for(int k = 0; k < 4; k++) {
        int nx = fx + dx[k], ny = fy + dy[k];
        if(ok(nx,ny) && vis[nx][ny]) cnt++;
    }
    if(sx == fx && sy == fy) {
        cout << (cnt >= 1 ? "YES" : "NO") << "\n";
        return 0;
    }
    if(g[fx][fy] == 'X') {
        cout << (cnt >= 1 ? "YES" : "NO") << "\n";
    } else {
        cout << (cnt >= 2 ? "YES" : "NO") << "\n";
    }
}
