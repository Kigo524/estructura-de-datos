#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;

// Función para insertar al inicio
bool insertarInicio(Nodo** cabeza, int valor) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevo == NULL) return false;
    nuevo->dato = valor;
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
    return true;
}

// Función para insertar al final
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

// Función para insertar en una posición específica
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

// Función para eliminar el nodo al inicio
bool eliminarInicio(Nodo** cabeza) {
    if (*cabeza == NULL) return false;
    Nodo* temp = *cabeza;
    *cabeza = temp->siguiente;
    free(temp);
    temp = NULL;
    return true;
}

// Función para eliminar el nodo al final
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

// Función para eliminar en una posición específica
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

// Función para imprimir la lista
void imprimirLista(Nodo* cabeza) {
    Nodo* actual = cabeza;
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

// Función para ordenar la lista usando el método de selección
void ordenarSeleccion(Nodo* cabeza) {
    if (cabeza == NULL) return; // Si la lista está vacía, no hay nada que ordenar

    Nodo* actual = cabeza; // Comienza desde la cabeza

    while (actual != NULL) {
        Nodo* indiceMin = actual; // Marca el nodo actual como el mínimo
        Nodo* siguiente = actual->siguiente; // Comienza a buscar en el resto de la lista

        while (siguiente != NULL) {
            if (siguiente->dato < indiceMin->dato) {
                indiceMin = siguiente; // Actualiza el índice mínimo si se encuentra un menor
            }
            siguiente = siguiente->siguiente; // Avanza al siguiente nodo
        }

        // Intercambiar si es necesario
        if (indiceMin != actual) {
            int temp = actual->dato; // Guarda el dato actual
            actual->dato = indiceMin->dato; // Asigna el dato del mínimo al actual
            indiceMin->dato = temp; // Asigna el dato temporal al mínimo
        }
        actual = actual->siguiente; // Avanza al siguiente nodo
    }
}

// Función principal
int main() {
    Nodo* lista = NULL;

    // Insertar datos en la lista
    insertarInicio(&lista, 30);
    insertarFinal(&lista, 10);
    insertarEnPosicion(&lista, 20, 1); // Inserta 20 en la posición 1

    printf("Lista original:\n");
    imprimirLista(lista); // Muestra la lista original

    // Ordenar la lista
    ordenarSeleccion(lista);

    printf("\nLista ordenada:\n");
    imprimirLista(lista); // Muestra la lista ordenada

    // Limpiar la lista
    eliminarInicio(&lista);
    printf("\nEliminamos al inicio:\n");
    imprimirLista(lista);

    eliminarFinal(&lista);
    printf("\nEliminamos al final:\n");
    imprimirLista(lista);

    eliminarFinal(&lista);
    printf("\nEliminamos al final otra vez:\n");
    imprimirLista(lista); // Muestra la lista vacía

    return 0;
}