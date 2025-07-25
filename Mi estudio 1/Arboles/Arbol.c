#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ---ESTRUCTURA---

// Estructura del nodo del árbol binario
typedef struct Nodo {
    int dato;
    struct Nodo* izquierdo;
    struct Nodo* derecho;
} Nodo;

// Estructuras auxiliares para una cola (para recorrido por niveles)
typedef struct NodoCola {
    Nodo* nodoArbol;
    struct NodoCola* siguiente;
} NodoCola;

typedef struct {
    NodoCola* frente;
    NodoCola* final;
} Cola;

// ---COLA---

// Crea una cola vacía
Cola* crearCola() {
    Cola* c = (Cola*) malloc(sizeof(Cola));
    c->frente = NULL;
    c->final = NULL;
    return c;
}

// Inserta un nodo al final de la cola
void encolar(Cola* c, Nodo* nodo) {
    NodoCola* nuevo = (NodoCola*) malloc(sizeof(NodoCola));
    nuevo->nodoArbol = nodo;
    nuevo->siguiente = NULL;

    if (c->final != NULL) {
        c->final->siguiente = nuevo;
    } else {
        c->frente = nuevo;
    }

    c->final = nuevo;
}

// Saca un nodo del inicio de la cola
Nodo* desencolar(Cola* c) {
    if (c->frente == NULL) return NULL;

    NodoCola* temp = c->frente;
    Nodo* nodo = temp->nodoArbol;
    c->frente = temp->siguiente;

    if (c->frente == NULL) c->final = NULL;

    free(temp);
    return nodo;
}

// Verifica si la cola está vacía
bool colaVacia(Cola* c) {
    return c->frente == NULL;
}

// ---ARBOL---

// Crea un nuevo nodo del árbol con un valor
Nodo* crearNodo(int valor) {
    Nodo* nuevo = (Nodo*) malloc(sizeof(Nodo));
    nuevo->dato = valor;
    nuevo->izquierdo = NULL;
    nuevo->derecho = NULL;
    return nuevo;
}

// Inserta un nodo en el primer lugar disponible (nivel más bajo, lo más a la derecha)
Nodo* insertar(Nodo* raiz, int valor) {
    Nodo* nuevo = crearNodo(valor);

    // Si el árbol está vacío, el nuevo nodo será la raíz
    if (raiz == NULL) return nuevo;

    // Una cola para recorrer el árbol por niveles
    Cola* c = crearCola();
    encolar(c, raiz);

    while (!colaVacia(c)) {
        Nodo* actual = desencolar(c);

        // Insertar a la izquierda si está libre
        if (actual->izquierdo == NULL) {
            actual->izquierdo = nuevo;
            break;
        } else {
            encolar(c, actual->izquierdo);
        }

        // Insertar a la derecha si está libre
        if (actual->derecho == NULL) {
            actual->derecho = nuevo;
            break;
        } else {
            encolar(c, actual->derecho);
        }
    }

    free(c);
    return raiz;
}

// Elimina un nodo y lo reemplaza con el último nodo insertado (como en un heap)
Nodo* eliminar(Nodo* raiz, int valor) {
    if (raiz == NULL) return NULL;

    // Caso especial: solo hay un nodo
    if (raiz->izquierdo == NULL && raiz->derecho == NULL) {
        if (raiz->dato == valor) {
            free(raiz);
            return NULL;
        } else {
            return raiz;
        }
    }

    // Recorrido por niveles para encontrar:
    // - nodoObjetivo: el que queremos eliminar
    // - ultimo: el último nodo (más a la derecha en el último nivel)
    // - padreDelUltimo: el padre del nodo más reciente insertado
    Cola* c = crearCola();
    encolar(c, raiz);

    Nodo* nodoObjetivo = NULL;
    Nodo* ultimo = NULL;
    Nodo* padreDelUltimo = NULL;

    while (!colaVacia(c)) {
        Nodo* actual = desencolar(c);

        if (actual->dato == valor) {
            nodoObjetivo = actual;
        }

        if (actual->izquierdo != NULL) {
            padreDelUltimo = actual;
            encolar(c, actual->izquierdo);
        }

        if (actual->derecho != NULL) {
            padreDelUltimo = actual;
            encolar(c, actual->derecho);
        }

        ultimo = actual;  // Guarda el último visitado
    }

    // Si se encontró el nodo a eliminar
    if (nodoObjetivo != NULL) {
        // Copia el dato del último nodo
        nodoObjetivo->dato = ultimo->dato;

        // Elimina físicamente el último nodo
        if (padreDelUltimo->derecho == ultimo) {
            free(padreDelUltimo->derecho);
            padreDelUltimo->derecho = NULL;
        } else if (padreDelUltimo->izquierdo == ultimo) {
            free(padreDelUltimo->izquierdo);
            padreDelUltimo->izquierdo = NULL;
        }
    }

    free(c);
    return raiz;
}

// Muestra el árbol visualmente (de lado)
void mostrarArbol(Nodo* raiz, int nivel) {
    if (raiz == NULL) return;

    mostrarArbol(raiz->derecho, nivel + 1);

    //for (int i = 0; i < nivel; i++) printf("   ");
    //printf("%d\n", raiz->dato);

    int i = 0;
    while (i < nivel){
        printf("    ");
        i++;
    }
    printf("%d\n", raiz->dato);

    mostrarArbol(raiz->izquierdo, nivel + 1);
}

// Libera toda la memoria del árbol (postorden)
void liberarArbol(Nodo* raiz) {
    if (raiz != NULL) {
        liberarArbol(raiz->izquierdo);
        liberarArbol(raiz->derecho);
        free(raiz);
    }
}

// ------------------- FUNCIÓN PRINCIPAL -------------------

int main() {
    Nodo* arbol = NULL;

    // Insertar varios valores
    arbol = insertar(arbol, 10);
    arbol = insertar(arbol, 20);
    arbol = insertar(arbol, 30);
    arbol = insertar(arbol, 40);
    arbol = insertar(arbol, 50);

    printf("Árbol después de insertar:\n");
    mostrarArbol(arbol, 0);

    // Eliminar un nodo específico
    printf("\nEliminando el nodo con valor 20...\n");
    arbol = eliminar(arbol, 20);

    printf("Árbol después de eliminar:\n");
    mostrarArbol(arbol, 0);

    liberarArbol(arbol);
    return 0;
}