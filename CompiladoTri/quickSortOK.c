#include <stdio.h>
#include <stdlib.h>

// Estructura del nodo de la lista doblemente ligada
typedef struct Nodo {
    int valor;
    struct Nodo* anterior;
    struct Nodo* siguiente;
} Nodo;

// Crear un nuevo nodo con un valor dado
Nodo* crearNodo(int valor) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->valor = valor;
    nuevo->anterior = NULL;
    nuevo->siguiente = NULL;
    return nuevo;
}

// Insertar un nuevo nodo al final de la lista
void insertarFinal(Nodo** cabeza, int valor) {
    Nodo* nuevo = crearNodo(valor);

    if (*cabeza == NULL) {
        *cabeza = nuevo;
        return;
    }

    Nodo* actual = *cabeza;
    while (actual->siguiente != NULL) {
        actual = actual->siguiente;
    }

    actual->siguiente = nuevo;
    nuevo->anterior = actual;
}

// Imprimir todos los valores de la lista
void imprimirLista(Nodo* cabeza) {
    Nodo* actual = cabeza;
    while (actual != NULL) {
        printf("%d ", actual->valor);
        actual = actual->siguiente;
    }
    printf("\n");
}

// Obtener el último nodo de la lista
Nodo* obtenerUltimo(Nodo* nodo) {
    while (nodo != NULL && nodo->siguiente != NULL) {
        nodo = nodo->siguiente;
    }
    return nodo;
}

// Intercambiar los valores de dos nodos
void intercambiar(Nodo* a, Nodo* b) {
    int temp = a->valor;
    a->valor = b->valor;
    b->valor = temp;
}

// Particionar la lista usando el último nodo como pivote
Nodo* particion(Nodo* inicio, Nodo* fin) {
    int pivote = fin->valor;
    Nodo* i = inicio->anterior;
    Nodo* j = inicio;

    while (j != fin) {
        if (j->valor <= pivote) {
            if (i == NULL) {
                i = inicio; // Si i es NULL, comenzamos desde el inicio
            } else {
                i = i->siguiente; // Avanzamos i
            }
            intercambiar(i, j); // Intercambiamos los valores
        }
        j = j->siguiente; // Avanzamos j
    }

    if (i == NULL) {
        i = inicio; // Si i es NULL, el pivote es el primer nodo
    } else {
        i = i->siguiente; // Avanzamos i
    }

    intercambiar(i, fin); // Intercambiamos el pivote con el nodo en i
    return i; // Devolvemos el pivote
}

// QuickSort recursivo
void quickSortRecursivo(Nodo* inicio, Nodo* fin) {
    if (fin != NULL && inicio != fin && inicio != fin->siguiente) {
        Nodo* pivote = particion(inicio, fin);
        quickSortRecursivo(inicio, pivote->anterior); // Ordenar la parte izquierda
        quickSortRecursivo(pivote->siguiente, fin);   // Ordenar la parte derecha
    }
}

// Función principal para ordenar la lista
Nodo* quickSort(Nodo* cabeza) {
    Nodo* fin = obtenerUltimo(cabeza);
    quickSortRecursivo(cabeza, fin);
    return cabeza;
}

// Buscar un valor en la lista ordenada
Nodo* buscarValor(Nodo* cabeza, int valorBuscado) {
    Nodo* actual = cabeza;

    while (actual != NULL) {
        if (actual->valor == valorBuscado) {
            return actual; // Encontrado
        }
        if (actual->valor > valorBuscado) {
            return NULL; // Ya pasó el lugar donde debería estar
        }
        actual = actual->siguiente;
    }

    return NULL; // No se encontró
}

// MAIN de prueba
int main() {
    Nodo* lista = NULL;

    // Insertar valores (puedes cambiar o agregar más)
    insertarFinal(&lista, 40);
    insertarFinal(&lista, 20);
    insertarFinal(&lista, 70);
    insertarFinal(&lista, 10);
    insertarFinal(&lista, 50);
    insertarFinal(&lista, 20); // Valor repetido

    printf("Lista antes de ordenar:\n");
    imprimirLista(lista);

    // Ordenar la lista
    lista = quickSort(lista);

    printf("Lista después de ordenar con QuickSort:\n");
    imprimirLista(lista);

    // Buscar un valor
    int valorBuscado = 20;
    Nodo* encontrado = buscarValor(lista, valorBuscado);
    if (encontrado != NULL) {
        printf("Valor %d encontrado en la lista.\n", valorBuscado);
    } else {
        printf("Valor %d no se encuentra en la lista.\n", valorBuscado);
    }

    return 0;
}