#ifndef LISTA_H
#define LISTA_H

// Definición del nodo
typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;

// Prototipos de funciones
void insertarInicio(Nodo** cabeza, int valor);
void insertarFinal(Nodo** cabeza, int valor);
void insertarEnPosicion(Nodo** cabeza, int valor, int posicion);
void eliminarInicio(Nodo** cabeza);
void eliminarFinal(Nodo** cabeza);
void eliminarEnPosicion(Nodo** cabeza, int posicion);
void imprimirLista(Nodo* cabeza);

#endif