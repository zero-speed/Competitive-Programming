#include <bits/stdc++.h> // complexity O(log(N))
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// ordered_multiset
typedef tree<
    pair<long long, long long>, // {valor, id}
    null_type,
    less<pair<long long, long long>>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_multiset;

int main() {
    ordered_multiset ms;
    long long id = 0;

    //Insertar (permitiendo duplicados)
    ms.insert({10, id++});
    ms.insert({10, id++});

    //k-esimo elemento (0-index)
    cout << "Elemento en posicion 2: ";
    cout << ms.find_by_order(2)->first << endl;

    //cuantos < x
    cout << "Menores que 20: ";
    cout << ms.order_of_key({20, 0}) << endl;

    //cuantos <= x
    cout << "Menores o iguales que 20: ";
    cout << ms.order_of_key({20, LLONG_MAX}) << endl;

    //eliminar UNA ocurrencia de x
    long long borrar = 10;
    auto it = ms.lower_bound({borrar, 0});
    if (it != ms.end() && it->first == borrar)
        ms.erase(it);

    return 0;
}