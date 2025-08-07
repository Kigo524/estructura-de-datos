#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Definición de la estructura Elemento que contendrá los datos
typedef struct {
    int dato; // Aquí puedes agregar otros campos si usas Estudiante
} Elemento;

// Definición de la estructura Nodo que representa cada nodo de la lista
typedef struct Nodo {
    Elemento info; // Información del nodo
    struct Nodo* siguiente; // Puntero al siguiente nodo
} Nodo;

// Función para insertar un nuevo nodo al inicio de la lista
bool insertarInicio(Nodo** final, Elemento nuevoDato) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo)); // Reserva memoria para el nuevo nodo
    if (!nuevo) return false; // Verifica si la memoria fue asignada correctamente

    nuevo->info = nuevoDato; // Asigna el dato al nuevo nodo
    if (*final == NULL) { // Si la lista está vacía
        nuevo->siguiente = nuevo; // El nuevo nodo apunta a sí mismo
        *final = nuevo; // El nuevo nodo se convierte en el final de la lista
    } else {
        nuevo->siguiente = (*final)->siguiente; // El nuevo nodo apunta al primer nodo
        (*final)->siguiente = nuevo; // El final apunta al nuevo nodo
    }
    return true; // Inserción exitosa
}

// Función para insertar un nuevo nodo al final de la lista
bool insertarFinal(Nodo** final, Elemento nuevoDato) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo)); // Reserva memoria para el nuevo nodo
    if (!nuevo) return false; // Verifica si la memoria fue asignada correctamente

    nuevo->info = nuevoDato; // Asigna el dato al nuevo nodo
    if (*final == NULL) { // Si la lista está vacía
        nuevo->siguiente = nuevo; // El nuevo nodo apunta a sí mismo
        *final = nuevo; // El nuevo nodo se convierte en el final de la lista
    } else {
        nuevo->siguiente = (*final)->siguiente; // El nuevo nodo apunta al primer nodo
        (*final)->siguiente = nuevo; // El final apunta al nuevo nodo
        *final = nuevo; // Actualiza el final a ser el nuevo nodo
    }
    return true; // Inserción exitosa
}

// Función para insertar un nuevo nodo en una posición específica
bool insertarEnPos(Nodo** final, Elemento nuevoDato, int pos) {
    if (pos < 0) return false; // Verifica si la posición es válida

    if (*final == NULL || pos == 0) // Si la lista está vacía o se inserta en la posición 0
        return insertarInicio(final, nuevoDato); // Llama a insertar al inicio

    Nodo* actual = (*final)->siguiente; // Comienza desde el primer nodo
    int i = 0;
    while (i < pos - 1 && actual != *final) { // Recorre hasta la posición deseada
        actual = actual->siguiente; // Avanza al siguiente nodo
        i++;
    }

    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo)); // Reserva memoria para el nuevo nodo
    if (!nuevo) return false; // Verifica si la memoria fue asignada correctamente

    nuevo->info = nuevoDato; // Asigna el dato al nuevo nodo
    nuevo->siguiente = actual->siguiente; // El nuevo nodo apunta al siguiente nodo
    actual->siguiente = nuevo; // El nodo actual apunta al nuevo nodo

    if (actual == *final) // Si se insertó al final
        *final = nuevo; // Actualiza el final a ser el nuevo nodo

    return true; // Inserción exitosa
}

// Función para eliminar el nodo al inicio de la lista
bool eliminarInicio(Nodo** final) {
    if (*final == NULL) return false; // Verifica si la lista está vacía

    Nodo* inicio = (*final)->siguiente; // Guarda el primer nodo

    if (*final == inicio) { // Si solo hay un nodo
        free(inicio); // Libera la memoria del nodo
        *final = NULL; // La lista queda vacía
    } else {
        (*final)->siguiente = inicio->siguiente; // El final apunta al segundo nodo
        free(inicio); // Libera la memoria del nodo
    }
    return true; // Eliminación exitosa
}

// Función para eliminar el nodo al final de la lista
bool eliminarFinal(Nodo** final) {
    if (*final == NULL) return false; // Verifica si la lista está vacía

    Nodo* actual = (*final)->siguiente; // Comienza desde el primer nodo

    if (actual == *final) { // Si solo hay un nodo
        free(*final); // Libera la memoria del nodo
        *final = NULL; // La lista queda vacía
    } else {
        while (actual->siguiente != *final) { // Recorre hasta el penúltimo nodo
            actual = actual->siguiente; // Avanza al siguiente nodo
        }
        actual->siguiente = (*final)->siguiente; // El penúltimo apunta al primer nodo
        free(*final); // Libera la memoria del nodo final
        *final = actual; // Actualiza el final a ser el penúltimo nodo
    }
    return true; // Eliminación exitosa
}

// Función para eliminar un nodo en una posición específica
bool eliminarEnPos(Nodo** final, int pos) {
    if (*final == NULL || pos < 0) return false; // Verifica si la lista está vacía o si la posición es válida

    if (pos == 0) // Si se quiere eliminar el primer nodo
        return eliminarInicio(final); // Llama a eliminar al inicio

    Nodo* actual = (*final)->siguiente; // Comienza desde el primer nodo
    int i = 0;

    while (i < pos - 1 && actual->siguiente != (*final)->siguiente) { // Recorre hasta la posición deseada
        actual = actual->siguiente; // Avanza al siguiente nodo
        i++;
    }

    Nodo* temp = actual->siguiente; // Guarda el nodo a eliminar

    if (temp == (*final)->siguiente) // Si se quiere eliminar el primer nodo
        return eliminarInicio(final); // Llama a eliminar al inicio

    if (temp == *final) // Si se quiere eliminar el último nodo
        *final = actual; // Actualiza el final a ser el nodo actual

    actual->siguiente = temp->siguiente; // El nodo actual apunta al siguiente del nodo a eliminar
    free(temp); // Libera la memoria del nodo a eliminar
    temp = NULL; // Evita punteros colgantes
    return true; // Eliminación exitosa
}

// Función para recorrer y mostrar los elementos de la lista
void recorrer(Nodo* final) {
    if (final == NULL) { // Verifica si la lista está vacía
        printf("Lista vacía\n");
        return; // Sale de la función
    }

    Nodo* actual = final->siguiente; // Comienza desde el primer nodo
    do {
        printf("%d ", actual->info.dato); // Muestra el dato del nodo
        actual = actual->siguiente; // Avanza al siguiente nodo
    } while (actual != final->siguiente); // Continúa hasta volver al inicio
    printf("\n"); // Salto de línea al final
}

// Función principal
int main() {
    Nodo* lista = NULL; // Inicializa la lista como vacía
    int opcion, pos;
    Elemento est; // Cambié Estudiante a Elemento para que coincida con la estructura

    do {
        // Menú de opciones
        printf("\n--- MENU LISTA CIRCULAR DE ESTUDIANTES ---\n");
        printf("1. Insertar al inicio\n");
        printf("2. Insertar al final\n");
        printf("3. Insertar en posición\n");
        printf("4. Eliminar al inicio\n");
        printf("5. Eliminar al final\n");
        printf("6. Eliminar en posición\n");
        printf("7. Mostrar lista\n");
        printf("0. Salir\n");
        printf("Elige una opción: ");
        scanf("%d", &opcion);
        getchar(); // Limpia el buffer de enter

        switch (opcion) {
            case 1:
            case 2:
            case 3:
                printf("Dato: "); // Cambié "Matricula" a "Dato" para que coincida con Elemento
                scanf("%d", &est.dato); // Lee el dato
                getchar(); // Limpia el buffer

                // Inserta según la opción elegida
                if (opcion == 1)
                    insertarInicio(&lista, est);
                else if (opcion == 2)
                    insertarFinal(&lista, est);
                else {
                    printf("Posición: ");
                    scanf("%d", &pos);
                    insertarEnPos(&lista, est, pos);
                }
                break;

            case 4:
                if (!eliminarInicio(&lista))
                    printf("No se pudo eliminar. Lista vacía.\n");
                break;

            case 5:
                if (!eliminarFinal(&lista))
                    printf("No se pudo eliminar. Lista vacía.\n");
                break;

            case 6:
                printf("Posición: ");
                scanf("%d", &pos);
                if (!eliminarEnPos(&lista, pos))
                    printf("No se pudo eliminar. Posición inválida o lista vacía.\n");
                break;

            case 7:
                recorrer(lista); // Cambié recorrerLista a recorrer para que coincida con la función
                break;

            case 0:
                printf("Saliendo...\n");
                break;

            default:
                printf("Opción inválida. Intenta de nuevo.\n");
        }

    } while (opcion != 0); // Continúa hasta que el usuario elija salir

    return 0; // Fin del programa
}