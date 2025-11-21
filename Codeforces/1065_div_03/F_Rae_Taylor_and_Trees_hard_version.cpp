/**                                            (⌐■_■)
*  Author :    zero_speed                       /█\   GG...
*  Created :   2025-11-20                      _/ \_ 
*  File :      F_Rae_Taylor_and_Trees_hard_version.cpp
**/
#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl "\n"
#define ll long long
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<pair<int, int>> cola;
    set<int> ans;
    for(int i=n-1;i>=0;i--){
        ans.insert(a[i]);
        auto l = ans.upper_bound(a[i]);
        auto r = ans.end();
        for(auto it = l; it != r; ++it){
            //cout<<a[i]<<" "<<*it<<endl; 
            cola.push_back({a[i], *it});
        }
        auto x =ans.lower_bound(a[i]);
        r=prev(ans.end());
        ans.erase(x,r);
    }
    if(ans.size()>1){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
        for(auto p:cola){
            cout<<p.first<<" "<<p.second<<endl;
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
