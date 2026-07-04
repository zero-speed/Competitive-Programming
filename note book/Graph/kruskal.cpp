// Algoritmo de Kruskal para encontrar el Árbol de Expansión Mínima (MST)
// Complejidad: O(m log m) donde m es el número de aristas
// - O(m log m) para ordenar las aristas
// - O(m * α(n)) para las operaciones de DSU (α es inversa de Ackermann, prácticamente O(1))
// - Total: O(m log m)

#include <bits/stdc++.h>
using namespace std;

// Estructura de Datos Union-Find (Disjoint Set Union)
class DSU {
public:
    vector<int> padre;
    vector<int> rango;
    
    DSU(int n) {
        padre.resize(n + 1);
        rango.resize(n + 1, 0);
        // Inicializar cada nodo como su propio padre
        for(int i = 1; i <= n; i++) {
            padre[i] = i;
        }
    }
    
    // Encontrar el representante (raíz) del conjunto con compresión de ruta
    int encontrar(int u) {
        if(padre[u] != u) {
            padre[u] = encontrar(padre[u]); // Compresión de ruta
        }
        return padre[u];
    }
    
    // Unir dos conjuntos usando unión por rango
    bool unir(int u, int v) {
        int raiz_u = encontrar(u);
        int raiz_v = encontrar(v);
        
        if(raiz_u == raiz_v) return false; // Ya están en el mismo conjunto
        
        // Unión por rango: conectar el árbol más pequeño al más grande
        if(rango[raiz_u] < rango[raiz_v]) {
            padre[raiz_u] = raiz_v;
        } else if(rango[raiz_u] > rango[raiz_v]) {
            padre[raiz_v] = raiz_u;
        } else {
            padre[raiz_v] = raiz_u;
            rango[raiz_u]++;
        }
        return true;
    }
};

void kruskal(int n, vector<tuple<int,int,int>> &aristas) {
    // Ordenar aristas por peso (primero elemento de la tupla)
    sort(aristas.begin(), aristas.end());
    
    DSU dsu(n);
    int peso_mst = 0;
    int aristas_agregadas = 0;
    
    // Procesar cada arista en orden de peso creciente
    for(auto &[peso, u, v] : aristas) {
        // Si u y v están en componentes diferentes
        if(dsu.unir(u, v)) {
            peso_mst += peso;
            aristas_agregadas++;
            
            // El MST tiene exactamente n-1 aristas
            if(aristas_agregadas == n - 1) break;
        }
    }
    
    cout << "Peso del MST: " << peso_mst << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    // Leer las aristas: (peso, nodo_u, nodo_v)
    vector<tuple<int,int,int>> aristas(m);
    for(int i = 0; i < m; i++) {
        int u, v, peso;
        cin >> u >> v >> peso;
        aristas[i] = {peso, u, v};
    }
    
    kruskal(n, aristas);
    
    return 0;
}