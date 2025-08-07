#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definimos el nodo del árbol binario de búsqueda
typedef struct Nodo {
    int valor;                  // Valor que guarda el nodo
    struct Nodo* izquierdo;     // Apuntador al hijo izquierdo
    struct Nodo* derecho;       // Apuntador al hijo derecho
} Nodo;

// Crear un nuevo nodo
Nodo* crearNodo(int valor) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->valor = valor;
    nuevo->izquierdo = NULL;
    nuevo->derecho = NULL;
    return nuevo;
}

// Insertar un valor en el árbol
Nodo* insertar(Nodo* raiz, int valor) {
    // Si el árbol está vacío, creamos un nuevo nodo
    if (raiz == NULL) {
        return crearNodo(valor);
    }

    // Si el valor es menor, insertamos en el subárbol izquierdo
    if (valor < raiz->valor) {
        raiz->izquierdo = insertar(raiz->izquierdo, valor);
    } 
    // Si el valor es mayor, insertamos en el subárbol derecho
    else if (valor > raiz->valor) {
        raiz->derecho = insertar(raiz->derecho, valor);
    }

    // Si es igual, no se inserta (no se permiten duplicados aquí)
    return raiz;
}

// Recorrido en orden (inorden)
void inOrden(Nodo* raiz) {
    if (raiz != NULL) {
        inOrden(raiz->izquierdo);        // Recorremos el subárbol izquierdo
        printf("%d ", raiz->valor);      // Mostramos el nodo actual
        inOrden(raiz->derecho);          // Recorremos el subárbol derecho
    }
}

// Recorrido en preorden
void preOrden(Nodo* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);      // Mostramos el nodo actual
        preOrden(raiz->izquierdo);       // Subárbol izquierdo
        preOrden(raiz->derecho);         // Subárbol derecho
    }
}

// Recorrido en postorden
void postOrden(Nodo* raiz) {
    if (raiz != NULL) {
        postOrden(raiz->izquierdo);      // Subárbol izquierdo
        postOrden(raiz->derecho);        // Subárbol derecho
        printf("%d ", raiz->valor);      // Mostramos el nodo actual
    }
}

// Buscar un valor en el árbol
bool buscar(Nodo* raiz, int valor) {
    // Si llegamos a un nodo vacío, no se encontró
    if (raiz == NULL) {
        return false;
    }

    // Si encontramos el valor, devolvemos true
    if (valor == raiz->valor) {
        return true;
    }

    // Si el valor es menor, buscamos en el subárbol izquierdo
    if (valor < raiz->valor) {
        return buscar(raiz->izquierdo, valor);
    } 
    // Si es mayor, buscamos en el derecho
    else {
        return buscar(raiz->derecho, valor);
    }
}

// Encontrar el nodo con el valor mínimo
Nodo* minimo(Nodo* raiz) {
    // Recorremos hacia la izquierda hasta encontrar el menor nodo
    while (raiz->izquierdo != NULL) {
        raiz = raiz->izquierdo;
    }
    return raiz;
}

// Eliminar un nodo del árbol
Nodo* eliminar(Nodo* raiz, int valor) {
    if (raiz == NULL) return NULL; // Árbol vacío

    if (valor < raiz->valor) {
        // Buscar en subárbol izquierdo
        raiz->izquierdo = eliminar(raiz->izquierdo, valor);
    } 
    else if (valor > raiz->valor) {
        // Buscar en subárbol derecho
        raiz->derecho = eliminar(raiz->derecho, valor);
    } 
    else {
        // Nodo encontrado

        // Caso 1: Solo tiene un hijo derecho o ninguno
        if (raiz->izquierdo == NULL) {
            Nodo* temp = raiz->derecho;
            free(raiz); // Liberamos el nodo actual
            return temp;
        } 
        // Caso 2: Solo tiene un hijo izquierdo
        else if (raiz->derecho == NULL) {
            Nodo* temp = raiz->izquierdo;
            free(raiz);
            return temp;
        }

        // Caso 3: Tiene dos hijos
        Nodo* temp = minimo(raiz->derecho);      // Buscamos el menor del subárbol derecho
        raiz->valor = temp->valor;               // Copiamos el valor del sucesor
        raiz->derecho = eliminar(raiz->derecho, temp->valor); // Eliminamos el sucesor
    }

    return raiz;
}

// Liberar toda la memoria del árbol (postorden)
void liberarArbol(Nodo* raiz) {
    if (raiz != NULL) {
        liberarArbol(raiz->izquierdo);
        liberarArbol(raiz->derecho);
        free(raiz);
    }
}

// ------------------- FUNCIÓN PRINCIPAL -------------------

int main() {
    Nodo* raiz = NULL;  // Árbol vacío

    // Insertamos varios valores
    raiz = insertar(raiz, 50);
    insertar(raiz, 30);
    insertar(raiz, 70);
    insertar(raiz, 20);
    insertar(raiz, 40);
    insertar(raiz, 60);
    insertar(raiz, 80);

    // Imprimimos los elementos en orden
    printf("Recorrido en orden: ");
    inOrden(raiz); // Salida esperada: 20 30 40 50 60 70 80
    printf("\n");

    // Buscar valores
    printf("¿Está el 40? %s\n", buscar(raiz, 40) ? "Sí" : "No");
    printf("¿Está el 25? %s\n", buscar(raiz, 25) ? "Sí" : "No");

    // Eliminar un nodo (por ejemplo, 30)
    raiz = eliminar(raiz, 30);

    printf("Tras eliminar 30: ");
    inOrden(raiz); // Salida esperada: 20 40 50 60 70 80
    printf("\n");

    // Liberar la memoria del árbol
    liberarArbol(raiz);
    return 0;
}