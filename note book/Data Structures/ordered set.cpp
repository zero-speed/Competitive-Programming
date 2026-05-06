#include <bits/stdc++.h> // complexity O(log (n))
#include <ext/pb_ds/assoc_container.hpp> // necesario
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// Definicion de ordered_set
typedef tree<
    long long,              // tipo de dato
    null_type,              // mapped type (null para set)
    less<long long>,        // comparador
    rb_tree_tag,            // tipo de arbol (red-black)
    tree_order_statistics_node_update // soporte para order statistics
> ordered_set;

int main() {
    ordered_set s;

    //Insertar
    s.insert(10);
    s.insert(20);

    // find_by_order(k)
    // devuelve iterador al elemento en posicion k (0-index)
    cout << "Elemento en posicion 1: ";
    cout << *s.find_by_order(1) << endl; // segundo elemento

    // order_of_key(x)
    // cuantos elementos son menores que x
    cout << "Elementos menores que 30: ";
    cout << s.order_of_key(30) << endl;

    return 0;
}