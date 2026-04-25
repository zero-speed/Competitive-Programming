/*
i -> indice inicial
k=0:  5   2   4   7   1   3   6   0   8  Consulta [L, R]
k=1:  2   2   4   1   1   3   0   0      [---- rango ----]
k=2:  2   1   1   1   0   0              [-- 2^j --]     <- comienza en L 
k=3:  0   0                                 [-- 2^j --]  <- termina en R
                                        -> combinas 2 valores 
*/
struct sparce_table{   
    vector<vector<int>> tabla;

    sparce_table(int n){
        int filas = log2(n) + 1;
        tabla.resize(filas, vector<int>(n));
    }
    void build(vector<int> &arr){           // O(nlogn)       
        int n = arr.size();
        for(int i=0;i<n;i++){
            tabla[0][i] = arr[i];
        }
        for(int i=1;i<tabla.size();i++){
            for(int j=0;j+(1<<i)<=n;j++){
                tabla[i][j]=min(tabla[i-1][j], tabla[i-1][j+(1<<(i-1))]);
            }
        }
    }
    int query(int l, int r){                // O(1)
        int k=log2(r-l+1);
        return min(tabla[k][l], tabla[k][r-(1<<k)+1]);
    }

};