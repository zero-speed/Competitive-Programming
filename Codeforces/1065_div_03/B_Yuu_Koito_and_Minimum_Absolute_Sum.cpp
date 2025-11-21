/**                                            (⌐■_■)
*  Author :    zero_speed                       /█\   GG...
*  Created :   2025-11-20                      _/ \_ 
*  File :      B_Yuu_Koito_and_Minimum_Absolute_Sum.cpp
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
    if(a[0]==-1){
        if(a[n-1]!=-1){
            a[0]=a[n-1];
        }else{
            a[0]=a[n-1]=0;
        }
    }
    if(a[n-1]==-1){
        if(a[0]!=-1){
            a[n-1]=a[0];
        }else{
            a[n-1]=a[0]=0;
        }
    }
    cout<<abs(a[n-1]-a[0])<<endl;
    for(int i=0;i<n;i++){
        if(a[i]==-1){
            cout<<0<<" ";;
        }else{
            cout<<a[i]<<" ";
        }
    }
    cout<<endl;
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