/**                                            (⌐■_■)
*  Author :    zero_speed                       /█\   GG...
*  Created :   2025-11-20                      _/ \_ 
*  File :      C_1_Renako_Amaori_and_XOR_Game_easy_version.cpp
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
        if(a[i]==b[i] && a[i]==1){
            x++;
            y++;
        }
    }
    for(int i=0;i<n;i++){
        if(i%2==0){
            if(a[i]!=b[i]){
                if(x%2==0){
                    x++;
                }else{
                    y++;
                }
            }
        }else{
            if(a[i]!=b[i]){
                if(y%2==0){
                    y++;
                }else{
                    x++;
                }
            }
        }
    }
    if(x%2==y%2){
        cout<<"Tie"<<endl;
    }else{
        if(x%2){
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