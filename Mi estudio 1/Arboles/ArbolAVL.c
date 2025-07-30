#include <stdio.h>
#include <stdlib.h>

//estruct de un nodo
typedef struct Nodo {
    int dato;
    int altura;
    struct Nodo* izquierdo;
    struct Nodo* derecho;
} Nodo;

//devuelve altura de nodo, NULL si es 0
int altura(Nodo* nodo) {
    if (nodo == NULL)
        return 0;
    return nodo->altura;
}

//calcula diferencia de alturas entre izq y der.
//si es >1 o <-1, el arbol esta desequilibrado y necesita rotaciones
int obtenerBalance(Nodo* nodo) {
    if (nodo == NULL)
        return 0;
    return altura(nodo->izquierdo) - altura(nodo->derecho);
}

//Calucar altura de un nuevo nodo. caluclando el maximo entre dos valores
int max(int a, int b) {
    return (a > b) ? a : b;
}

//rotacion derecha: cuando izq es mas alto
Nodo* rotarDerecha(Nodo* y) {
    Nodo* x = y->izquierdo;
    Nodo* T2 = x->derecho;

    // Rotación
    x->derecho = y;
    y->izquierdo = T2;

    // Actualiza alturas
    y->altura = max(altura(y->izquierdo), altura(y->derecho)) + 1;
    x->altura = max(altura(x->izquierdo), altura(x->derecho)) + 1;

    return x; // Nueva raíz
}

//rotacion izquierda: cuando der es mas alto
Nodo* rotarIzquierda(Nodo* x) {
    Nodo* y = x->derecho;
    Nodo* T2 = y->izquierdo;

    // Rotación
    y->izquierdo = x;
    x->derecho = T2;

    // Actualiza alturas
    x->altura = max(altura(x->izquierdo), altura(x->derecho)) + 1;
    y->altura = max(altura(y->izquierdo), altura(y->derecho)) + 1;

    return y; // Nueva raíz
}

//insertar
Nodo* insertar(Nodo* nodo, int dato) {
    // Caso base: nuevo nodo
    if (nodo == NULL) {
        Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
        nuevo->dato = dato;
        nuevo->izquierdo = nuevo->derecho = NULL;
        nuevo->altura = 1;
        return nuevo;
    }

    // Insertar recursivamente según valor
    if (dato < nodo->dato)
        nodo->izquierdo = insertar(nodo->izquierdo, dato);
    else if (dato > nodo->dato)
        nodo->derecho = insertar(nodo->derecho, dato);
    else
        return nodo; // No se permiten duplicados

    // Actualiza altura del nodo actual
    nodo->altura = 1 + max(altura(nodo->izquierdo), altura(nodo->derecho));

    // Calcula el balance
    int balance = obtenerBalance(nodo);

    // Casos de rotación
    if (balance > 1 && dato < nodo->izquierdo->dato) // Izquierda-Izquierda
        return rotarDerecha(nodo);

    if (balance < -1 && dato > nodo->derecho->dato) // Derecha-Derecha
        return rotarIzquierda(nodo);

    if (balance > 1 && dato > nodo->izquierdo->dato) { // Izquierda-Derecha
        nodo->izquierdo = rotarIzquierda(nodo->izquierdo);
        return rotarDerecha(nodo);
    }

    if (balance < -1 && dato < nodo->derecho->dato) { // Derecha-Izquierda
        nodo->derecho = rotarDerecha(nodo->derecho);
        return rotarIzquierda(nodo);
    }

    return nodo; // No se requiere rotación
}

//eliminar
Nodo* minimoValorNodo(Nodo* nodo) {
    Nodo* actual = nodo;
    while (actual->izquierdo != NULL)
        actual = actual->izquierdo;
    return actual;
}

Nodo* eliminar(Nodo* raiz, int dato) {
    if (raiz == NULL)
        return raiz;

    // Búsqueda del nodo
    if (dato < raiz->dato)
        raiz->izquierdo = eliminar(raiz->izquierdo, dato);
    else if (dato > raiz->dato)
        raiz->derecho = eliminar(raiz->derecho, dato);
    else {
        // Nodo encontrado: tiene un hijo o ninguno
        if ((raiz->izquierdo == NULL) || (raiz->derecho == NULL)) {
            Nodo* temp = raiz->izquierdo ? raiz->izquierdo : raiz->derecho;

            if (temp == NULL) {
                temp = raiz;
                raiz = NULL;
            } else {
                *raiz = *temp;
            }
            free(temp);
        } else {
            // Nodo con dos hijos: se reemplaza con el menor del subárbol derecho
            Nodo* temp = minimoValorNodo(raiz->derecho);
            raiz->dato = temp->dato;
            raiz->derecho = eliminar(raiz->derecho, temp->dato);
        }
    }

    if (raiz == NULL)
        return raiz;

    // Actualizar altura
    raiz->altura = 1 + max(altura(raiz->izquierdo), altura(raiz->derecho));

    // Rebalanceo
    int balance = obtenerBalance(raiz);

    if (balance > 1 && obtenerBalance(raiz->izquierdo) >= 0)
        return rotarDerecha(raiz);

    if (balance > 1 && obtenerBalance(raiz->izquierdo) < 0) {
        raiz->izquierdo = rotarIzquierda(raiz->izquierdo);
        return rotarDerecha(raiz);
    }

    if (balance < -1 && obtenerBalance(raiz->derecho) <= 0)
        return rotarIzquierda(raiz);

    if (balance < -1 && obtenerBalance(raiz->derecho) > 0) {
        raiz->derecho = rotarDerecha(raiz->derecho);
        return rotarIzquierda(raiz);
    }

    return raiz;
}

//recorrido de menor a mayor
void inOrden(Nodo* raiz) {
    if (raiz != NULL) {
        inOrden(raiz->izquierdo);
        printf("%d ", raiz->dato);
        inOrden(raiz->derecho);
    }
}

int main() {
    Nodo* raiz = NULL;

    // Insertamos varios elementos
    raiz = insertar(raiz, 30);
    raiz = insertar(raiz, 20);
    raiz = insertar(raiz, 40);
    raiz = insertar(raiz, 10);
    raiz = insertar(raiz, 25);
    raiz = insertar(raiz, 35);
    raiz = insertar(raiz, 50);

    printf("Árbol AVL en orden: ");
    inOrden(raiz);
    printf("\n");

    // Eliminamos un nodo
    raiz = eliminar(raiz, 40);
    printf("Después de eliminar 40: ");
    inOrden(raiz);
    printf("\n");

    return 0;
}