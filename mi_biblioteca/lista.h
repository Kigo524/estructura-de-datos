#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Tipo genérico de nodo usando un tipo definido externamente llamado TIPO_DATO
#define TIPO_DATO Estudiante

typedef struct Nodo {
    TIPO_DATO dato;
    struct Nodo* siguiente;
} Nodo;

// Funciones genéricas
bool insertarInicio(Nodo** cabeza, TIPO_DATO valor) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevo == NULL) return false;
    nuevo->dato = valor;
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
    return true;
}

bool insertarFinal(Nodo** cabeza, TIPO_DATO valor) {
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

bool insertarEnPosicion(Nodo** cabeza, TIPO_DATO valor, int posicion) {
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

// El recorrido lo dejamos para que el usuario lo defina según su estructura

#endif