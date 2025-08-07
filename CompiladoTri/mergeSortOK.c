#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Estructura de un nodo de lista doblemente ligada
typedef struct Nodo {
    int dato;  // Dato almacenado
    struct Nodo* siguiente;   // Apunta al siguiente nodo
    struct Nodo* anterior;    // Apunta al nodo anterior
} Nodo;

Nodo* inicio = NULL; // Apunta al primer nodo de la lista
Nodo* fin = NULL;   // Apunta al último nodo de la lista

// Función para insertar al inicio
bool insertarInicio(Nodo** inicio, Nodo** fin, int valor) {
    Nodo* nuevo = malloc(sizeof(Nodo));  // Reservamos memoria para el nuevo nodo
    if (!nuevo) return false;  // Si falla la memoria, salimos

    nuevo->dato = valor;   // Guardamos el dato
    nuevo->anterior = NULL;    // No hay nodo antes, es el nuevo inicio
    nuevo->siguiente = *inicio;   // Su siguiente será el nodo actual de inicio

    if (*inicio != NULL)    // Si la lista no está vacía
        (*inicio)->anterior = nuevo;  // El nodo que era primero ahora apunta hacia atrás al nuevo
    else
        *fin = nuevo;   // Si la lista estaba vacía, también es el final

    *inicio = nuevo;   // Actualizamos el puntero de inicio
    return true;
}

// Función para insertar al final
bool insertarFinal(Nodo** inicio, Nodo** fin, int valor) {
    Nodo* nuevo = malloc(sizeof(Nodo));  // Creamos el nuevo nodo
    if (!nuevo) return false;

    nuevo->dato = valor;
    nuevo->siguiente = NULL;  // No tiene siguiente (es el último)
    nuevo->anterior = *fin;   // Su anterior es el nodo que era último

    if (*fin != NULL)
        (*fin)->siguiente = nuevo;  // El nodo actual de fin apunta al nuevo
    else
        *inicio = nuevo;  // Si estaba vacía, también es el inicio

    *fin = nuevo;  // Actualizamos el puntero fin
    return true;
}

// Función para insertar en una posición específica
bool insertarEnPosicion(Nodo** inicio, Nodo** fin, int valor, int pos) {
    if (pos < 0) return false;

    if (pos == 0)
        return insertarInicio(inicio, fin, valor);  // Insertar al inicio si posición es 0

    Nodo* actual = *inicio;
    int i = 0;

    while (actual != NULL && i < pos - 1) {   // Recorremos hasta llegar a la posición anterior
        actual = actual->siguiente;
        i++;
    }

    if (actual == NULL)
        return insertarFinal(inicio, fin, valor);   // Si llegamos al final, insertamos al final

    Nodo* nuevo = malloc(sizeof(Nodo));
    if (!nuevo) return false;

    nuevo->dato = valor;
    nuevo->siguiente = actual->siguiente;  // El nuevo apunta al siguiente del actual
    nuevo->anterior = actual;    // El nuevo apunta atrás al actual

    if (actual->siguiente != NULL)
        actual->siguiente->anterior = nuevo;  // El nodo siguiente apunta atrás al nuevo
    else
        *fin = nuevo;  // Si no hay siguiente, es el nuevo fin

    actual->siguiente = nuevo;  // El nodo actual apunta al nuevo
    return true;
}

// Función para eliminar el nodo al inicio
bool eliminarInicio(Nodo** inicio, Nodo** fin) {
    if (*inicio == NULL) return false;    // Lista vacía

    Nodo* temp = *inicio;
    *inicio = temp->siguiente;  // Saltamos al siguiente nodo

    if (*inicio != NULL)
        (*inicio)->anterior = NULL;  // El nuevo inicio ya no tiene anterior
    else
        *fin = NULL;  // Si quedó vacía, fin también es NULL

    free(temp);    // Liberamos memoria
    temp = NULL;
    return true;
}

// Función para eliminar el nodo al final
bool eliminarFinal(Nodo** inicio, Nodo** fin) {
    if (*fin == NULL) return false;   // Lista vacía

    Nodo* temp = *fin;
    *fin = temp->anterior;   // Retrocedemos al nodo anterior

    if (*fin != NULL)
        (*fin)->siguiente = NULL;   // El nuevo fin ya no tiene siguiente
    else
        *inicio = NULL;  // Si quedó vacía

    free(temp);
    temp = NULL;
    return true;
}

// Función para eliminar en una posición específica
bool eliminarEnPosicion(Nodo** inicio, Nodo** fin, int pos) {
    if (*inicio == NULL || pos < 0) return false;

    Nodo* actual = *inicio;
    int i = 0;

    while (actual != NULL && i < pos) {
        actual = actual->siguiente;
        i++;
    }

    if (actual == NULL) return false;

    if (actual->anterior != NULL)
        actual->anterior->siguiente = actual->siguiente;
    else
        *inicio = actual->siguiente;   // Si eliminamos el primero

    if (actual->siguiente != NULL)
        actual->siguiente->anterior = actual->anterior;
    else
        *fin = actual->anterior;    // Si eliminamos el último

    free(actual);
    actual = NULL;
    return true;
}

// Función para recorrer la lista
void recorrerLista(Nodo* inicio) {
    Nodo* actual = inicio;
    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->siguiente;
    }
    printf("\n");
}

// Función para recorrer la lista en reversa
void recorrerReversa(Nodo* fin) {
    Nodo* actual = fin;
    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->anterior;
    }
    printf("\n");
}

// Función para dividir la lista en dos mitades
Nodo* dividirLista(Nodo* cabeza) {
    if (cabeza == NULL || cabeza->siguiente == NULL) {
        return NULL;
    }

    Nodo* lento = cabeza;
    Nodo* rapido = cabeza->siguiente;

    // Avanzar hasta encontrar el punto medio
    while (rapido != NULL && rapido->siguiente != NULL) {
        lento = lento->siguiente;
        rapido = rapido->siguiente->siguiente;
    }

    Nodo* mitad = lento->siguiente;
    lento->siguiente = NULL;  // Dividir la lista
    mitad->anterior = NULL;   // Romper el enlace anterior

    return mitad;
}

Nodo* merge(Nodo* primero, Nodo* segundo) {
    if (primero == NULL) return segundo;
    if (segundo == NULL) return primero;

    if (primero->dato < segundo->dato) {
        primero->siguiente = merge(primero->siguiente, segundo);
        primero->siguiente->anterior = primero;
        primero->anterior = NULL;
        return primero;
    } else {
        segundo->siguiente = merge(primero, segundo->siguiente);
        segundo->siguiente->anterior = segundo;
        segundo->anterior = NULL;
        return segundo;
    }
}

Nodo* mergeSort(Nodo* cabeza) {
    if (cabeza == NULL || cabeza->siguiente == NULL) {
        return cabeza;
    }

    // Dividir la lista
    Nodo* mitad = dividirLista(cabeza);

    // Ordenar recursivamente ambas mitades
    Nodo* izquierda = mergeSort(cabeza);
    Nodo* derecha = mergeSort(mitad);

    // Fusionar las dos mitades ordenadas
    return merge(izquierda, derecha);
}

// Función para ordenar la lista usando Merge Sort
void ordenarLista(Nodo** inicio, Nodo** fin) {
    *inicio = mergeSort(*inicio);
    
    // Actualizar el puntero fin
    if (*inicio != NULL) {
        *fin = *inicio;
        while ((*fin)->siguiente != NULL) {
            *fin = (*fin)->siguiente;
        }
    } else {
        *fin = NULL;
    }
}

// Función principal
int main() {
    insertarFinal(&inicio, &fin, 30);
    insertarFinal(&inicio, &fin, 10);
    insertarFinal(&inicio, &fin, 20);
    
    printf("Antes de ordenar:\n");
    recorrerLista(inicio);  // 30 -> 10 -> 20 -> NULL
    
    ordenarLista(&inicio, &fin);
    
    printf("Después de ordenar:\n");
    recorrerLista(inicio);  // 10 -> 20 -> 30 -> NULL
    
    return 0;
}