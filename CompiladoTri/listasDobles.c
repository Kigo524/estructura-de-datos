#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definición de nodo
typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
    struct Nodo* anterior;
} Nodo;

// Variables globales para inicio y fin
Nodo* inicio = NULL;
Nodo* fin = NULL;

// Funciones
bool insertarInicio(int valor) {
    Nodo* nuevo = malloc(sizeof(Nodo));
    if (!nuevo) return false;

    nuevo->dato = valor;
    nuevo->anterior = NULL;
    nuevo->siguiente = inicio;

    if (inicio != NULL)
        inicio->anterior = nuevo;
    else
        fin = nuevo;

    inicio = nuevo;
    return true;
}

bool insertarFinal(int valor) {
    Nodo* nuevo = malloc(sizeof(Nodo));
    if (!nuevo) return false;

    nuevo->dato = valor;
    nuevo->siguiente = NULL;
    nuevo->anterior = fin;

    if (fin != NULL)
        fin->siguiente = nuevo;
    else
        inicio = nuevo;

    fin = nuevo;
    return true;
}

bool insertarEnPosicion(int valor, int pos) {
    if (pos < 0) return false;
    if (pos == 0) return insertarInicio(valor);

    Nodo* actual = inicio;
    int i = 0;
    while (actual != NULL && i < pos - 1) {
        actual = actual->siguiente;
        i++;
    }

    if (actual == NULL) return insertarFinal(valor);

    Nodo* nuevo = malloc(sizeof(Nodo));
    if (!nuevo) return false;

    nuevo->dato = valor;
    nuevo->siguiente = actual->siguiente;
    nuevo->anterior = actual;

    if (actual->siguiente != NULL)
        actual->siguiente->anterior = nuevo;
    else
        fin = nuevo;

    actual->siguiente = nuevo;
    return true;
}

bool eliminarInicio() {
    if (inicio == NULL) return false;

    Nodo* temp = inicio;
    inicio = inicio->siguiente;

    if (inicio != NULL)
        inicio->anterior = NULL;
    else
        fin = NULL;

    free(temp);
    temp = NULL;
    return true;
}

bool eliminarFinal() {
    if (fin == NULL) return false;

    Nodo* temp = fin;
    fin = fin->anterior;

    if (fin != NULL)
        fin->siguiente = NULL;
    else
        inicio = NULL;

    free(temp);
    temp = NULL;
    return true;
}

bool eliminarEnPosicion(int pos) {
    if (inicio == NULL || pos < 0) return false;

    Nodo* actual = inicio;
    int i = 0;
    while (actual != NULL && i < pos) {
        actual = actual->siguiente;
        i++;
    }

    if (actual == NULL) return false;

    if (actual->anterior != NULL)
        actual->anterior->siguiente = actual->siguiente;
    else
        inicio = actual->siguiente;

    if (actual->siguiente != NULL)
        actual->siguiente->anterior = actual->anterior;
    else
        fin = actual->anterior;

    free(actual);
    actual = NULL;
    return true;
}

void imprimirLista() {
    Nodo* actual = inicio;
    printf("Lista: ");
    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->siguiente;
    }
    printf("\n");
}

void imprimirReversa() {
    Nodo* actual = fin;
    printf("Lista (reversa): ");
    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->anterior;
    }
    printf("\n");
}

// Función principal con menú
int main() {
    int opcion, valor, posicion;

    do {
        printf("\n--- MENU LISTA DOBLE ---\n");
        printf("1. Insertar al inicio\n");
        printf("2. Insertar al final\n");
        printf("3. Insertar en posicion\n");
        printf("4. Eliminar al inicio\n");
        printf("5. Eliminar al final\n");
        printf("6. Eliminar en posicion\n");
        printf("7. Mostrar lista\n");
        printf("8. Mostrar reversa\n");
        printf("0. Salir\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Valor a insertar: ");
                scanf("%d", &valor);
                insertarInicio(valor);
                break;
            case 2:
                printf("Valor a insertar: ");
                scanf("%d", &valor);
                insertarFinal(valor);
                break;
            case 3:
                printf("Valor a insertar: ");
                scanf("%d", &valor);
                printf("Posicion: ");
                scanf("%d", &posicion);
                insertarEnPosicion(valor, posicion);
                break;
            case 4:
                eliminarInicio();
                break;
            case 5:
                eliminarFinal();
                break;
            case 6:
                printf("Posicion a eliminar: ");
                scanf("%d", &posicion);
                eliminarEnPosicion(posicion);
                break;
            case 7:
                imprimirLista();
                break;
            case 8:
                imprimirReversa();
                break;
            case 0:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }
    } while (opcion != 0);

    return 0;
}