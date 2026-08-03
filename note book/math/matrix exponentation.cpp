/*
si f(n) = f(n-1) + f(n-2) + 2f(n-3)
entonces la matriz necesaria seria usar los valores de las constantes
    1 1 2
A = 1 0 0
    0 1 0
Es decir en tamaño de la funcion dependente de cuantas funciones anteriores es necesario
entonces si tenemos una matriz base con respecto a los valores base f(0) = a, f(1) = b, f(c) = c
    a
B = b
    c
entonces f(n) = A**(n-1)*B

*/

#include<bits/stdc++.h>
using namespace std;

using ll =  long long;
using ull = unsigned long long;
#define endl "\n"

vector<int> dx = {0,0,-1,1};
vector<int> dy = {-1,1,0,0};

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int LG = 20;
const int N = 2;

vector<vector<ll>> A(N, vector<ll> (N,0));
vector<vector<ll>> I(N,vector<ll> (N,0));
vector<vector<ll>> base(N,vector<ll> (N,0));

void start(){
    for(int i=0; i<N; i++){
        I[i][i] = 1;
        A[0][i] = 1;
        if(i > 0) A[i][i-1] = 1;
        base[N-i-1][0] = i;        
    }
}

vector<vector<ll>> multi(vector<vector<ll>> A, vector<vector<ll>> B){
    vector<vector<ll>> res(N,vector<ll> (N,0));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++){
                res[i][j]  = (res[i][j] + (A[i][k]*B[k][j])%MOD)%MOD;
            }
        }
    }
    return res;
}

vector<vector<ll>> power(vector<vector<ll>> A, ll e){
    vector<vector<ll>> ans = I;
    while(e){
        if(e&1) ans = multi(ans,A);
        A = multi(A,A);
        e >>= 1;
    }
    return ans;
}

ll fibonacci(ll x){
    if(x == 0) return 0;
    vector<vector<ll>> fibo = multi(power(A,x-1),base);
    return fibo[0][0];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);   
    cout.tie(0);
    ll n;
    cin>>n;
    start();
    cout<<fibonacci(n)<<endl;


    return 0;
}