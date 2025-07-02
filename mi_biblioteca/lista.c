#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void insertarInicio(Nodo** cabeza, int valor) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = valor;
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
}

void insertarFinal(Nodo** cabeza, int valor) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = valor;
    nuevo->siguiente = NULL;

    if (*cabeza == NULL) {
        *cabeza = nuevo;
    } else {
        Nodo* actual = *cabeza;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }
}

void insertarEnPosicion(Nodo** cabeza, int valor, int posicion) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = valor;

    if (posicion == 0) {
        nuevo->siguiente = *cabeza;
        *cabeza = nuevo;
        return;
    }

    Nodo* actual = *cabeza;
    int i = 0;
    while (i < posicion - 1 && actual != NULL) {
        actual = actual->siguiente;
        i++;
    }

    if (actual == NULL) {
        printf("Posición inválida\n");
        free(nuevo);
        return;
    }

    nuevo->siguiente = actual->siguiente;
    actual->siguiente = nuevo;
}

void eliminarInicio(Nodo** cabeza) {
    if (*cabeza == NULL) return;

    Nodo* temp = *cabeza;
    *cabeza = (*cabeza)->siguiente;
    free(temp);
}

void eliminarFinal(Nodo** cabeza) {
    if (*cabeza == NULL) return;

    if ((*cabeza)->siguiente == NULL) {
        free(*cabeza);
        *cabeza = NULL;
        return;
    }

    Nodo* actual = *cabeza;
    while (actual->siguiente->siguiente != NULL) {
        actual = actual->siguiente;
    }

    free(actual->siguiente);
    actual->siguiente = NULL;
}

void eliminarEnPosicion(Nodo** cabeza, int posicion) {
    if (*cabeza == NULL) return;

    if (posicion == 0) {
        Nodo* temp = *cabeza;
        *cabeza = (*cabeza)->siguiente;
        free(temp);
        return;
    }

    Nodo* actual = *cabeza;
    int i = 0;
    while (i < posicion - 1 && actual->siguiente != NULL) {
        actual = actual->siguiente;
        i++;
    }

    if (actual->siguiente == NULL) {
        printf("Posición inválida\n");
        return;
    }

    Nodo* temp = actual->siguiente;
    actual->siguiente = temp->siguiente;
    free(temp);
}

void imprimirLista(Nodo* cabeza) {
    Nodo* actual = cabeza;
    printf("Lista: ");
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}