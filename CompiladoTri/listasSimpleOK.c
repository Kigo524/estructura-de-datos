#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;

bool insertarInicio(Nodo** cabeza, int valor) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevo == NULL) return false;
    nuevo->dato = valor;
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
    return true;
}

bool insertarFinal(Nodo** cabeza, int valor) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevo == NULL) return false;
    nuevo->dato = valor;
    nuevo->siguiente = NULL;

    if (*cabeza == NULL) {
        *cabeza = nuevo;
        return true;
    }

    Nodo* actual = *cabeza;
    while (actual->siguiente != NULL) {
        actual = actual->siguiente;
    }
    actual->siguiente = nuevo;
    return true;
}

bool insertarEnPosicion(Nodo** cabeza, int valor, int posicion) {
    if (posicion < 0) return false;
    if (posicion == 0) return insertarInicio(cabeza, valor);

    Nodo* actual = *cabeza;
    int i = 0;

    while (actual != NULL && i < posicion - 1) {
        actual = actual->siguiente;
        i++;
    }

    if (actual == NULL) return false;

    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevo == NULL) return false;
    nuevo->dato = valor;
    nuevo->siguiente = actual->siguiente;
    actual->siguiente = nuevo;
    return true;
}

bool eliminarInicio(Nodo** cabeza) {
    if (*cabeza == NULL) return false;
    Nodo* temp = *cabeza;
    *cabeza = temp->siguiente;
    free(temp);
    temp = NULL;
    return true;
}

bool eliminarFinal(Nodo** cabeza) {
    if (*cabeza == NULL) return false;

    if ((*cabeza)->siguiente == NULL) {
        free(*cabeza);
        *cabeza = NULL;
        return true;
    }

    Nodo* actual = *cabeza;
    while (actual->siguiente->siguiente != NULL) {
        actual = actual->siguiente;
    }

    free(actual->siguiente);
    actual->siguiente = NULL;
    return true;
}

bool eliminarEnPosicion(Nodo** cabeza, int posicion) {
    if (*cabeza == NULL || posicion < 0) return false;
    if (posicion == 0) return eliminarInicio(cabeza);

    Nodo* actual = *cabeza;
    int i = 0;

    while (actual->siguiente != NULL && i < posicion - 1) {
        actual = actual->siguiente;
        i++;
    }

    if (actual->siguiente == NULL) return false;

    Nodo* temp = actual->siguiente;
    actual->siguiente = temp->siguiente;
    free(temp);
    temp = NULL;
    return true;
}

void imprimirLista(Nodo* cabeza) {
    Nodo* actual = cabeza;
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

int main() {
    Nodo* lista = NULL;

    insertarInicio(&lista, 10);
    insertarFinal(&lista, 20);
    insertarEnPosicion(&lista, 15, 1); // Inserta 15 en la posición 1

    imprimirLista(lista); // 10 -> 15 -> 20 -> NULL

    eliminarEnPosicion(&lista, 1); // Elimina el nodo en la posición 1
    imprimirLista(lista); // 10 -> 20 -> NULL

    eliminarInicio(&lista);
    eliminarFinal(&lista);
    imprimirLista(lista); // NULL

    return 0;
}