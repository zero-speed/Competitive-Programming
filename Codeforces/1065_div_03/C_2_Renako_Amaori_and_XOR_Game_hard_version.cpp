/**                                            (⌐■_■)
*  Author :    zero_speed                       /█\   GG...
*  Created :   2025-11-20                      _/ \_ 
*  File :      C_2_Renako_Amaori_and_XOR_Game_hard_version.cpp
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
    int x=0, y=0;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
        if(a[i]==b[i]){
            x^=a[i];
            y^=a[i];
        }
    }
    for(int i=0;i<n;i++){
        if(i%2==0){
            if(a[i]!=b[i]){
                if(x^a[i] >  y^b[i]){
                    x^=a[i];
                    y^=b[i];
                }else{
                    x^=b[i];
                    y^=a[i];
                }
            }
        }else{
            if(a[i]!=b[i]){
                if(y^a[i] >  x^b[i]){
                    y^=a[i];
                    x^=b[i];
                }else{
                    y^=b[i];
                    x^=a[i];
                }
            }
        }
    }
    if(x==y){
        cout<<"Tie"<<endl;
    }else{
        if(x>y){
            cout<<"Ajisai"<<endl;
        }else{
            cout<<"Mai"<<endl;
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