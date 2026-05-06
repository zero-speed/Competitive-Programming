#include <iostream>  // complexity (n long (n))
using namespace std;

struct Nodo {
    long long valor;
    Nodo* izq;
    Nodo* der;

    Nodo(long long v) {
        valor = v;
        izq = der = nullptr;
    }
};

// Insertar
Nodo* insertar(Nodo* raiz, long long valor) {
    if (raiz == nullptr)
        return new Nodo(valor);

    if (valor < raiz->valor)
        raiz->izq = insertar(raiz->izq, valor);
    else if (valor > raiz->valor)
        raiz->der = insertar(raiz->der, valor);

    return raiz;
}

// Buscar
bool buscar(Nodo* raiz, long long valor) {
    if (raiz == nullptr)
        return false;

    if (raiz->valor == valor)
        return true;

    if (valor < raiz->valor)
        return buscar(raiz->izq, valor);
    else
        return buscar(raiz->der, valor);
}

// Encontrar minimo
Nodo* encontrarMin(Nodo* raiz) {
    while (raiz && raiz->izq != nullptr)
        raiz = raiz->izq;
    return raiz;
}

// Eliminar
Nodo* eliminar(Nodo* raiz, long long valor) {
    if (raiz == nullptr)
        return raiz;

    if (valor < raiz->valor) {
        raiz->izq = eliminar(raiz->izq, valor);
    } else if (valor > raiz->valor) {
        raiz->der = eliminar(raiz->der, valor);
    } else {
        // Caso 1: sin hijos
        if (raiz->izq == nullptr && raiz->der == nullptr) {
            delete raiz;
            return nullptr;
        }
        // Caso 2: un hijo
        else if (raiz->izq == nullptr) {
            Nodo* temp = raiz->der;
            delete raiz;
            return temp;
        }
        else if (raiz->der == nullptr) {
            Nodo* temp = raiz->izq;
            delete raiz;
            return temp;
        }
        // Caso 3: dos hijos
        Nodo* temp = encontrarMin(raiz->der);
        raiz->valor = temp->valor;
        raiz->der = eliminar(raiz->der, temp->valor);
    }

    return raiz;
}

int main() {
    Nodo* raiz = nullptr;

    // Insertar valores
    raiz = insertar(raiz, 50);
    insertar(raiz, 30);
    insertar(raiz, 70);
    insertar(raiz, 20);
    insertar(raiz, 40);

    cout << "Buscar 40: ";
    cout << (buscar(raiz, 40) ? "Encontrado" : "No encontrado") << endl;

    cout << "Eliminar 30\n";
    raiz = eliminar(raiz, 30);

    cout << "Inorden despues de eliminar: ";
    cout << endl;

    return 0;
}