// Algoritmo de Kruskal para encontrar el Arbol de Expansion Minima (MST)
// Complejidad: O(m log m) donde m es el numero de aristas
// - O(m log m) para ordenar las aristas
// - O(m * alpha(n)) para las operaciones de DSU (alpha inversa de Ackermann, practicamente O(1))
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
        for (int i = 1; i <= n; i++) {
            padre[i] = i;
        }
    }

    // Encontrar el representante (raiz) del conjunto con compresion de ruta
    int encontrar(int u) {
        if (padre[u] != u) {
            padre[u] = encontrar(padre[u]); // Compresion de ruta
        }
        return padre[u];
    }

    // Unir dos conjuntos usando union por rango
    bool unir(int u, int v) {
        int raiz_u = encontrar(u);
        int raiz_v = encontrar(v);

        if (raiz_u == raiz_v) return false; // Ya estan en el mismo conjunto

        // Union por rango: conectar el arbol mas pequeno al mas grande
        if (rango[raiz_u] < rango[raiz_v]) {
            padre[raiz_u] = raiz_v;
        } 
        else if (rango[raiz_u] > rango[raiz_v]) {
            padre[raiz_v] = raiz_u;
        } 
        else {
            padre[raiz_v] = raiz_u;
            rango[raiz_u]++;
        }

        return true;
    }
};

void kruskal(int n, vector<tuple<int,int,int>> &aristas) {
    // Ordenar aristas por peso
    sort(aristas.begin(), aristas.end());

    DSU dsu(n);
    int peso_mst = 0;
    int aristas_agregadas = 0;

    for (auto &[peso, u, v] : aristas) {
        if (dsu.unir(u, v)) {
            peso_mst += peso;
            aristas_agregadas++;

            if (aristas_agregadas == n - 1) break;
        }
    }

    cout << "Peso del MST: " << peso_mst << endl;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<tuple<int,int,int>> aristas(m);

    for (int i = 0; i < m; i++) {
        int u, v, peso;
        cin >> u >> v >> peso;
        aristas[i] = {peso, u, v};
    }

    kruskal(n, aristas);

    return 0;
}