
| Propiedad | Formula |
|---|---|
| Algoritmo de Euclides | $\gcd(a,b)=\gcd(b,a\bmod b)$ |
| Resta multiple | $\gcd(a,b)=\gcd(a-kb,b)$ |
| Resta multiple | $\gcd(a,b)=\gcd(a,b-ka)$ |
| Escalamiento | $\gcd(ka,kb)=\|k\|\cdot\gcd(a,b)$ |
| Asociatividad | $\gcd(a,b,c)=\gcd(\gcd(a,b),c)$ |
| Generalizacion | $\gcd(a_1,\dots,a_n)=\gcd(\gcd(a_1,\dots,a_{n-1}),a_n)$ |
| Coprimos y MCM | $\gcd(a,b)=1 \Rightarrow \operatorname{lcm}(a,b)=ab$ |
| Identidad de Bezout | $d=\gcd(a,b)\Rightarrow ax+by=d$ |
| Combinacion lineal | $ax+by$ siempre es múltiplo de $\gcd(a,b)$ |
| Coprimos | $\gcd(a,b)=1\Rightarrow ax+by=1$ tiene solución entera |
| Lema de Euclides | $\gcd(a,b)=1 \land a\mid bc\Rightarrow a\mid c$ |
| Coprimo con potencias | $\gcd(a,b)=1\Rightarrow\gcd(a,b^k)=1$ |
| Producto de coprimos | $\gcd(a,b)=1\land\gcd(a,c)=1\Rightarrow\gcd(a,bc)=1$ |
| Potencias | $\gcd(a^m,a^n)=a^{\min(m,n)}$ |
| Potencias coprimas | $\gcd(a,b)=1\Rightarrow\gcd(a^m,b^n)=1$ |
| Divisibilidad | $a\mid b\Rightarrow\gcd(a,b)=a$ |
| Propagación de divisibilidad | $a\mid b\Rightarrow\gcd(a,c)\mid\gcd(b,c)$ |
| Reducción por MCD | $d=\gcd(a,b)\Rightarrow\gcd(\frac ad,\frac bd)=1$ |
| Forma reducida | $a=da',\ b=db',\ \gcd(a',b')=1$ |
| Invariante suma | $\gcd(a+b,b)=\gcd(a,b)$ |
| Invariante resta | $\gcd(a-b,b)=\gcd(a,b)$ |
| Invariante módulo | $\gcd(a+kb,b)=\gcd(a,b)$ |
| Invariante módulo | $\gcd(a+kb,a)=\gcd(a,b)$ |
| Primo | $p$ primo $\Rightarrow \gcd(p,a)\in\{1,p\}$ |
| Lema de Euclides primo | $p\mid ab\Rightarrow p\mid a\ \text{o}\ p\mid b$ |