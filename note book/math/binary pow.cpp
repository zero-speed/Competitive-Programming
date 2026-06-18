/*
la idea es simple
el exponente se representa en binario, y se procesa bit a bit.
*/
#define ll long long
ll binpow(ll base, ll expo){
    ll ans=1;
    while(expo>0){
        if(expo&1) ans*=base; // Si el bit menos significativo es 1, multiplicamos la base al resultado
        base*=base; // Elevamos la base al cuadrado para el siguiente bit
        expo>>=1; // Desplazamos el exponente a la derecha para procesar el siguiente bit
    }
    return ans; 
}
/*
supongamos que queremos calcular 3^13:
- Inicialmente, ans = 1, base = 3, expo = 13 (1101 en binario)
1. expo & 1 = 1 (bit menos significativo es 1), 
entonces ans = ans * base = 1 * 3 = 3.
Luego, base = base * base = 3 * 3 = 9,
y expo = expo >> 1 = 6 (110 en binario).
2. expo & 1 = 0 (bit menos significativo es 0),
entonces no multiplicamos ans por base.
Luego, base = base * base = 9 * 9 = 81,
y expo = expo >> 1 = 3 (11 en binario).
3. expo & 1 = 1 (bit menos significativo es 1),
entonces ans = ans * base = 3 * 81 = 243.
Luego, base = base * base = 81 * 81 = 6561,
y expo = expo >> 1 = 1 (1 en binario).
4. expo & 1 = 1 (bit menos significativo es 1),
entonces ans = ans * base = 243 * 6561 = 1594323.
Luego, base = base * base = 6561 * 6561 = 43046721,
y expo = expo >> 1 = 0 (0 en binario).
Finalmente, el resultado es ans = 1594323, que es igual a 3^13.
*/