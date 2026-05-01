#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

const int INF = 1e9;
const int MOD = 1e9 + 7;

ll LIS(vector<int>& a, int n){
    int len = 0;
    vector<int> dp(n,1);
    for(int i=1; i<n; i++){
        for(int j=0; j<n; j++){
            if(a[i] > a[j]){
                dp[i] = max(dp[i], dp[j] +1);
            }
        }
        len = max(len,dp[i]);
    }
    return len;
}
// este es un comentario de prueba
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    cout<<LIS(a,n)<<endl;
    

    return 0;
}