/*
imagina que quieres calcualr el fibonacci de 4561
podriamos representar fibo(1) = 1 y fibo(2) = 2
o tambien como un vector [1 2] y para calcular por el
tercer termino, podriamos multiplicar por una matriz
[1 1]
[1 0]
entonces tendriamos 
[1 2] * [1 1] 
        [1 0]
lo que nos da [3 1]
y para el cuarto termino, multiplicamos el resultado por la misma matriz
[3 1] * [1 1]
        [1 0]
para el quinto termino, multiplicamos el resultado por la misma matriz
[4 3] * [1 1]
        [1 0]
podemos ver el patron
entonces podriamos generalizarlo
fibo(n) = [fibo(1) fibo(2)] * [1 1]* [1 0] *
                              [1 0]  [1 0]   ... n-2 veces
entonces para calcular el fibonacci de 4561, solo tenemos que multiplicar 
la matriz N veces y usar la tecnica de exponenciacion BINARIA para multiplicar 
la matriz log(n) veces, lo que nos da un resultado en O(log(n))
*/

#define ll long long
#define MOD 1000000007 
ll fibonacci(ll n){
    if(n==1) return 1;
    if(n==2) return 2;
    ll F[2][2] = {{1,1},{1,0}};
    ll res[2][2] = {{1,0},{0,1}}; // Matriz identidad
    n -= 2; // Ya tenemos los dos primeros terminos
    while(n>0){
        if(n&1){ // Si el bit menos significativo es 1
            // Multiplicamos res por F
            ll temp[2][2];
            for(int i=0;i<2;i++){
                for(int j=0;j<2;j++){
                    temp[i][j] = (res[i][0]*F[0][j] + res[i][1]*F[1][j]) % MOD;
                }
            }
            for(int i=0;i<2;i++){
                for(int j=0;j<2;j++){
                    res[i][j] = temp[i][j];
                }
            }
        }
        // Elevamos F al cuadrado
        ll temp[2][2];
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                temp[i][j] = (F[i][0]*F[0][j] + F[i][1]*F[1][j]) % MOD;
            }
        }
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                F[i][j] = temp[i][j];
            }
        }
        n>>=1; // Desplazamos el exponente a la derecha para procesar el siguiente bit
    }
    return res[0][0]; // El resultado es el primer elemento de la matriz resultante
}

/*
fibonacci de 4561 es 687995182, y se calcula en O(log(4561)).
*/