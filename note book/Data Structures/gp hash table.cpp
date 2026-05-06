// suele ser mas rapido en la practica que unordered_map
#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long

// compilar con: g++ -std=gnu++17 -O2 archivo.cpp

// hash robusto para evitar colisiones (anti-hack)
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int main() {
    // sin custom_hash (no recomendado en CF)
    gp_hash_table<ll, ll> mapa1;

    // con custom_hash (recomendado)
    gp_hash_table<ll, ll, custom_hash> mapa2;

    return 0;
}