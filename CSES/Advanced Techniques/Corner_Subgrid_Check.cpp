/**                                            (⌐■_■)
*  Author :    zero_speed                       /█\   GG...
*  Created :   2025-11-18                      _/ \_ 
*  File :      Corner_Subgrid_Check.cpp
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
    vector<string> arr(n);
    set<char> chars;
    map<char, vector<pair<int, int>>> pos;

    for(int i=0;i<n;i++){
        cin>>arr[i];
        for(int j=0;j<m;j++){
            pos[arr[i][j]].emplace_back(i,j);
            chars.insert(arr[i][j]);
        }
        
    }

}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}