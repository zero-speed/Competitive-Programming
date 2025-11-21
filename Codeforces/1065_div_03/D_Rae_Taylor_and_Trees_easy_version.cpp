/**                                            (⌐■_■)
*  Author :    zero_speed                       /█\   GG...
*  Created :   2025-11-20                      _/ \_ 
*  File :      D_Rae_Taylor_and_Trees_easy_version.cpp
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
    set<int> ans;
    for(int i=n-1;i>=0;i--){
        ans.insert(a[i]);
        auto l=ans.lower_bound(a[i]);
        auto r=prev(ans.end());
        ans.erase(l,r);
    }
    if(ans.size()>1){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
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
