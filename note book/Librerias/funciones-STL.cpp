<cmath>
/*

Las siguientes funciones devuelven valores en double, float o long double y pueden tomar como argumento valores del mismo tipo

Funcion     | Dominio             | Rango                | Tipo (C++)
------------|---------------------|----------------------|-------------------
sin(x)      | x in R              | [-1, 1]              | double
cos(x)      | x in R              | [-1, 1]              | double
tan(x)      | x in R*             | R                    | double

asin(x)     | x in [-1, 1]        | [-pi/2, pi/2]        | double
acos(x)     | x in [-1, 1]        | [0, pi]              | double
atan(x)     | x in R              | [-pi/2, pi/2]        | double
atan2(y,x)  | x,y in R            | [-pi, pi]            | double

sinh(x)     | x in R              | R                    | double
cosh(x)     | x in R              | [1, +inf)            | double
tanh(x)     | x in R              | (-1, 1)              | double

exp(x)      | x in R              | (0, +inf)            | double

log(x)      | x > 0               | R                    | double
log10(x)    | x > 0               | R                    | double

sqrt(x)     | x >= 0              | [0, +inf)            | double

ceil(x)     | x in R              | Z                    | double -> int/ll
floor(x)    | x in R              | Z                    | double -> int/ll

fabs(x)     | x in R              | [0, +inf)            | double
abs(x)      | x in Z              | [0, +inf)            | int / long long

<algorithm> and <numeric>
Las siguientes funciones son esenciales para arreglos y vectores

Funcion                                         | Que hace                              | Orden
------------------------------------------------|---------------------------------------|------
lower_bound(v.begin(), v.end(), x)              | primer elemento >= x                  | si
upper_bound(v.begin(), v.end(), x)              | primer elemento > x                   | si
binary_search(v.begin(), v.end(), x)            | verifica si x existe                  | si
equal_range(v.begin(), v.end(), x)              | rango [lower_bound, upper_bound)      | si

sort(v.begin(), v.end())                        | ordena ascendente                     | no
sort(v.begin(), v.end(), greater<int>())        | ordena descendente                    | no

is_sorted(v.begin(), v.end())                   | verifica si esta ordenado             | no

reverse(v.begin(), v.end())                     | invierte el arreglo                   | no

nth_element(v.begin(), v.begin()+k, v.end())    | k-esimo elemento en posicion correcta | no

min_element(v.begin(), v.end())                 | minimo elemento                       | no
max_element(v.begin(), v.end())                 | maximo elemento                       | no

count(v.begin(), v.end(), x)                    | cuenta ocurrencias de x               | no
find(v.begin(), v.end(), x)                     | busca x (lineal)                      | no

Son intrinsics del compilador (principalmente de GCC y Clang).

Funcion                          | Que hace                                  | Tipo
---------------------------------|--------------------------------------------|-------------------
__builtin_popcount(x)            | cuenta bits en 1 (int)                     | int
__builtin_popcountll(x)          | cuenta bits en 1 (long long)               | int

__builtin_clz(x)                 | ceros a la izquierda (int)                 | int
__builtin_clzll(x)               | ceros a la izquierda (ll)                  | int

__builtin_ctz(x)                 | ceros a la derecha (int)                   | int
__builtin_ctzll(x)               | ceros a la derecha (ll)                    | int

__builtin_parity(x)              | paridad (#bits 1 % 2)                      | int

__builtin_ffs(x)                 | primer bit encendido (1-indexado)          | int

__builtin_expect(x, val)         | hint de prediccion de ramas                | int

*/