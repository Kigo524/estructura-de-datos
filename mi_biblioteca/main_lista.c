#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Primero defines la estructura
typedef struct {
    int matricula;
    char nombre[50];
    char apellido[50];
    int edad;
    bool esRegular;
} Estudiante;

// Luego defines el tipo genérico
#define TIPO_DATO Estudiante

// Y ahora sí incluyes el archivo con las funciones
#include "lista.h"

// Función para imprimir un estudiante
void imprimirEstudiante(Estudiante e) {
    printf("Matricula: %d\n", e.matricula);
    printf("Nombre: %s %s\n", e.nombre, e.apellido);
    printf("Edad: %d\n", e.edad);
    printf("Regular: %s\n", e.esRegular ? "Sí" : "No");
}

// Función para recorrer lista
void recorrerLista(Nodo* cabeza) {
    Nodo* actual = cabeza;
    while (actual != NULL) {
        imprimirEstudiante(actual->dato);
        printf("-----------\n");
        actual = actual->siguiente;
    }
}

Estudiante crearEstudianteDesdeTeclado() {
    Estudiante e;
    printf("Matricula: "); scanf("%d", &e.matricula);
    printf("Nombre: "); scanf(" %[^\n]", e.nombre);
    printf("Apellido: "); scanf(" %[^\n]", e.apellido);
    printf("Edad: "); scanf("%d", &e.edad);
    int regular;
    printf("¿Es regular? (1: Sí, 0: No): "); scanf("%d", &regular);
    e.esRegular = (regular == 1);
    return e;
}

int main() {
    Nodo* lista = NULL;
    int opcion;

    do {
        printf("\n--- Menú ---\n");
        printf("1. Insertar estudiante al inicio\n");
        printf("2. Insertar estudiante al final\n");
        printf("3. Insertar estudiante en posición\n");
        printf("4. Eliminar estudiante al inicio\n");
        printf("5. Eliminar estudiante al final\n");
        printf("6. Eliminar estudiante en posición\n");
        printf("7. Ver estudiantes\n");
        printf("0. Salir\n");
        printf("Opción: ");
        scanf("%d", &opcion);

        Estudiante e;
        int pos;

        switch (opcion) {
            case 1:
                e = crearEstudianteDesdeTeclado();
                insertarInicio(&lista, e);
                break;
            case 2:
                e = crearEstudianteDesdeTeclado();
                insertarFinal(&lista, e);
                break;
            case 3:
                e = crearEstudianteDesdeTeclado();
                printf("Posición: ");
                scanf("%d", &pos);
                insertarEnPosicion(&lista, e, pos);
                break;
            case 4:
                eliminarInicio(&lista);
                break;
            case 5:
                eliminarFinal(&lista);
                break;
            case 6:
                printf("Posición: ");
                scanf("%d", &pos);
                eliminarEnPosicion(&lista, pos);
                break;
            case 7:
                recorrerLista(lista);
                break;
            case 0:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción inválida.\n");
        }
    } while (opcion != 0);

    return 0;
}